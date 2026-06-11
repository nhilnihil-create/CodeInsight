#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
  stack<char> stack;
  string s;
  int len,i,flag;
  while(1){
    flag=0;
    getline(cin,s);
    if(s==".") break;
    len=s.size();
    for(i=0;i<len;i++){
      if(s[i]=='('||s[i]=='[') stack.push(s[i]);
      else if(s[i]==')'){
	if(stack.empty()!=true&&stack.top()=='('){
	  stack.pop();
	}
        else{
	  flag=1;
	  break;
	}
      }
      else if(s[i]==']'){
	if(stack.empty()!=true&&stack.top()=='['){
	  stack.pop();
	}
        else{
	  flag=1;
	  break;
	}
      }
    }
    if(flag==0&&stack.empty()==true){
      cout << "yes" << endl;
    }
    else{
      if(stack.empty()!=true){
	while(1){
	  stack.pop();
	  if(stack.empty()==true) break;
	}
      }
      cout << "no" << endl;
    }
  }
  return 0;
}