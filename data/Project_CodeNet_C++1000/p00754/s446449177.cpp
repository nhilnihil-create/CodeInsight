#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main(void){
  string s;
  int k,l,i;
  stack<char> st;
  int flag;
  while(getline(cin,s)){
    if(s.length()==1&&s[0]=='.') break;
    while(!st.empty()) st.pop();
    flag=0;
    for(i=0;i<s.length();i++){
      if(s[i]=='('||s[i]=='['){
        st.push(s[i]);
      }
      if(s[i]==')'||s[i]==']'){
        if(st.empty()) flag=1;
        if(!st.empty()){
          if(s[i]==')'){
            if('('!=st.top()) flag=1;
          }
          if(s[i]==']'){
            if('['!=st.top()) flag=1;
          }
          st.pop();
        }
      }
    }
    if(!st.empty()) flag=1;
    if(flag) cout<<"no"<<endl;
    else cout<<"yes"<<endl;
  }
  return 0;
}