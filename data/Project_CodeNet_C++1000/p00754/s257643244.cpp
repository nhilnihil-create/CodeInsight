#include <iostream>
#include <stack>
using namespace std;

int main(){
  string s;
  while(getline(cin,s)){
    if(s[0]=='.'&&s.size()==1)break;
    stack<char> st;
    int flag=1;
    for(int i=0;i<s.size();i++){
      if(s[i]=='(')st.push('(');
      if(s[i]=='[')st.push('[');
      if(s[i]==')'){
        if(st.empty()!=true&&st.top()=='('){
          st.pop();
        }else{
          flag=0;
          break;
        }
      }
      if(s[i]==']'){
        if(st.empty()!=true&&st.top()=='['){
          st.pop();
        }else{
          flag=0;
          break;
        }
      }
    }
    if(flag==1&&st.empty()){
      cout<<"yes"<<endl;
    }else{
      cout<<"no"<<endl;
    }
  }
  return 0;
}