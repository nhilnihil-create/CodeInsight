#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main(){

  string str;

  while(getline(cin, str)){
    if(str[0]=='.') break;

    stack<char> s;
    bool f=true;

    for(int i=0;i<str.size();i++){
      if(str[i]=='('||str[i]=='[') s.push(str[i]);
      if(str[i]==')'){
        if(s.empty()){
          f=false;
          break;
        }
        if(s.top()=='(') s.pop();
        else{
          f=false;
          break;
        }
      }else if(str[i]==']'){
        if(s.empty()){
          f=false;
          break;
        }
        if(s.top()=='[') s.pop();
        else{
          f=false;
          break;
        }
      }
    }
    if(f&&s.empty()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }

  return 0;
}