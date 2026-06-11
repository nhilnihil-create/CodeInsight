#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void){

  string s;
  while(getline(cin,s)){
    if(s==".")break;

    stack<char>st;
    for(int i=0;i<s.size();i++){
      if(s[i]=='(' || s[i]=='[')st.push(s[i]);
      else if(((s[i]==')' || s[i]==']') && st.empty()) ||
	      (s[i]==')' && st.top()=='[') ||
	      (s[i]==']' && st.top()=='(')){
	cout << "no" << endl;
	goto end;
      }
      else if(s[i]==')' || s[i]==']')st.pop();
    }
    if(st.empty())cout << "yes" << endl;
    else cout << "no" << endl;
  end:;
  }
  
  return 0;
}