#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;
int main(){
  string s;
  stack<char> st;
  bool flag;
  char c;
  int i;
  while(getline(cin, s)){
    if(s==".") break;
    flag=true;
    while(!st.empty()) st.pop();
    for(i=0;i<s.size();i++){
      if(!flag) break;
      if(s[i]=='('||s[i]=='['){
        st.push(s[i]);
      }
      if(s[i]==')'){
        if(st.empty()){flag=false;break;}
        c=st.top();
        st.pop();
        if(c!='('){
          flag=false;
        }
      }
      if(s[i]==']'){
        if(st.empty()){flag=false;break;}
        c=st.top();
        st.pop();
        if(c!='['){
          flag=false;
        }
      }
    }
    if(!st.empty()) flag=false;
    if(flag) cout<<"yes"<<endl;
    else cout <<"no"<<endl; 

  }

  return 0;
}