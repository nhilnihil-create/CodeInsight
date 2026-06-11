#include <bits/stdc++.h>
using namespace std;
void push(int);
int pop(void);

int stack_array[100];
int top=0;

char Str[100];

int main(){
  int x,y,top;
  char str[100];
  while(scanf("%s",str)!=EOF){
    if(str[0] == '+'){
      x = pop();
      y = pop();
      push(x + y);
    }else if(str[0] == '-'){
      y = pop();
      x = pop();
      push(x - y);
    }else if(str[0] == '*'){
      x = pop();
      y = pop();
      push(x * y);
    }else{
      push(atoi(str));
    }
  }

  printf("%d\n",pop());

  return 0;
}

void push(int x){
  stack_array[top] = x;
  top++;
}

int pop(){
  top--;
  return stack_array[top];
}