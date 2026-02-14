#include<iostream>
#include<cctype>
using namespace std;
#define SIZE 100
char stack[SIZE];
int top = -1;

void push(int num){
    top++; //0
    stack[top] = num;
}

int pop(){
    char topItem = stack[top];
    top--;
    return topItem;
}
                        //48+
int EvaluatePostfix(char arr[]){
    int i=0;
    while(arr[i]!=0){
        char c = arr[i];  //4

        if(isalnum(c)){
           push(c - '0') ;
        }
        else if(c=='+' || c== '-' || c=='*' || c=='/' ||c=='^'){
            int b = pop();
            int a = pop();

            switch(c){
                case '+':
                push(b+a);
                break;

                case '-':
                push(a-b);
                break;

                case '*':
                push(a*b);
                break;

                case '/':
                push(a/b);
                break;

                case '^':
                push(a^b);
                break;
            }
        }
        i++;
    }
    return pop();
}

int main(){
    char postfix[SIZE];
    cout<<"enter a postfix expression:";  //45+62-*  --> 36
    cin>>postfix;

    int ans = EvaluatePostfix(postfix);
    cout<< ans ;
}
