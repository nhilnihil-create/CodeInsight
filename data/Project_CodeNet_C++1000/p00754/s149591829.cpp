//The Balance of the World
#include<bits/stdc++.h>
using namespace std;

int main(){
  while(true){
    string s;
    getline(cin, s);
    if(s==".")break;
    bool flag=true;
    stack<char> st;
    for(int i=0; i<s.length(); i++){
      if(s[i]=='(' || s[i]=='[')st.push(s[i]);
      else if(s[i]==')'){
        if(st.size()==0){flag=false; break;}
        if(st.top()=='(')st.pop();
        else{flag=false; break;}
      }
      else if(s[i]==']'){
        if(st.size()==0){flag=false; break;}
        if(st.top()=='[')st.pop();
        else{flag=false; break;}
      }
    }
    if(st.size()!=0)flag=false;
    if(flag)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}