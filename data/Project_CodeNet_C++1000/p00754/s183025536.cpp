#include<iostream>
#include<stack>
using namespace std;
string str;

bool solve(){
  stack<char> st;
  for(int i=0;i<(int)str.size();i++){
    if(str[i]=='(')st.push(str[i]);
    else if(str[i]=='[')st.push(str[i]);
    else if(str[i]==')'){
      if(st.empty())return false;
      if(st.top()!='(')return false;
      st.pop();
    }else if(str[i]==']'){
      if(st.empty())return false;
      if(st.top()!='[')return false;
      st.pop();
    }
  }
  return st.empty();
}

int main(){
  while(1){
    getline(cin,str);
    if(str==".")break;
    if(solve())cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}