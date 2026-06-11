#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

int main(){
  char ch;
  while(1){
    stack<char> S;
    scanf("%c",&ch);
    if(ch=='.')break;
    int i=0;
    bool flag=0;

    while(1){
      if(i!=0)scanf("%c",&ch);
      if(ch=='.')break;
      
      if(ch=='[') S.push('[');
      else if(ch==']'&&S.size()==0)flag=1;
      else if(ch==']'&&S.top()=='[') S.pop();
      else if(ch==']') S.push(']');
      
      if(ch=='(')S.push('(');
      else if(ch==')'&&S.size()==0)flag=1;
      else if(ch==')'&&S.top()=='(') S.pop();
      else if(ch==')')S.push(')');

      i++;
    }

    if(S.size()==0&&flag!=1) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    scanf("%c",&ch);
  }
  return 0;
}