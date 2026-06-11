#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 1000

int A[MAX],top;

void push(int x){
  if(top>=MAX-1){
    cout<<"?????????????????????";
  }
  else{
    top++;
    A[top]=x;
  }
}

int pop(){
  if(top==0){
    cout<<"??¢??????????????????";
    return 0;
  }
  else{
    top--;
    return A[top+1];
  }
}

int main(){
  int a,b;
  int top=0;
  char s[100];
  while(cin>>s){
    if(s[0]=='+'){
      a=pop();
      b=pop();
      push(a+b);
    }
    else if(s[0]=='-'){
      a=pop();
      b=pop();
      push(b-a);
    }
    else if(s[0]=='*'){
      a=pop();
      b=pop();
      push(a*b);
    }
    else push(atoi(s));
  }

  cout<<pop()<<endl;

  return 0;
}
  
  