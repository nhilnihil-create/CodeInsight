#include <stdio.h>
#include <stdlib.h>

int top;
int stack[100];

int pop(){
    return stack[top--];
}

void push(int num){
    stack[++top] = num;
}

int main(){
    int a, b;
    char s[7];
    top = -1;

    while(scanf("%s", s) != EOF){
        if(s[0] == '+'){
            a = pop();
            b = pop();
            push(a+b);
        }
        else if(s[0] == '*'){
            a = pop();
            b = pop();
            push(a*b);
        }
        else if(s[0] == '-'){
            a = pop();
            b = pop();
            push(b-a);
        }
        else{
            push(atoi(s));
        }
    }
    printf("%d\n", pop());
    return 0;
}
