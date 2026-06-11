#include<bits/stdc++.h>
using namespace std;
int main(){
  string a;
  bool b;
  while(1){
    stack<char>stk;
    b=true;
    getline(cin,a);
    if(a==".") break;
    for(int i=0;i<a.size();i++){
      if(a[i]=='(') stk.push('(');
      else if(a[i]=='[') stk.push('[');
      else if(a[i]==')'){
	if(stk.empty()||stk.top()!='('){
	  b=false;
	  break;
	}else stk.pop();
      }else if(a[i]==']'){
	if(stk.empty()||stk.top()!='['){
	  b=false;
	  break;
	}else stk.pop();
      }
    }
    if(b==true && stk.empty()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}

