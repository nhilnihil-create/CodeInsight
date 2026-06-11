#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
  string s;
  int i;
  bool f;
  while(getline(cin,s),s[0]!='.'){
    stack<char> st;
    f=true;
    for(i=0;i<s.size();i++){
      if(s[i]=='('||s[i]=='['){
	st.push(s[i]);
      }else if(s[i]==')'||s[i]==']'){
	if(!st.empty()&&(st.top()+1==s[i]||st.top()+2==s[i]))st.pop();
	else f=false;
      }
    }
    puts(f&&st.empty()?"yes":"no");
  }
}