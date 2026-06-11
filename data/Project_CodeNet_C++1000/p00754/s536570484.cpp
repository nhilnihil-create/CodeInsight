#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
string s;
bool solve(){
  stack<char> st;
  rep(i,s.size()){
    if(s[i] == '(') st.push(s[i]);
    else if(s[i] == '[' ) st.push(s[i]);
    else if(s[i] == ')'){
      if(st.empty()) return false;
      if(st.top() != '(') return false;
      st.pop();
    }
    else if(s[i] == ']'){
      if(st.empty()) return false;
      if(st.top() != '[') return false;
      st.pop();
    }
  }
  return st.empty();
}
int main(){
  while(1){
    getline(cin,s);
    if(s == ".") break;
    if(solve()) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}

