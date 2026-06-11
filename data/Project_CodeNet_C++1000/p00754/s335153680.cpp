#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i =0;i<n;++i)

const int ma=3e6;
int ispr[ma];

int su[ma];


string in;

void solve(){
  stack<char> st;
  for(auto c:in){
    auto p = string("()[]").find(c);
    if( p == string::npos) continue;
    //cout << p << endl;
    if(p%2==0){
      st.push(c);
      continue;
    }
    
    if(st.empty()){
      cout << "no" << endl;
      return;
    }
    
    char c2 = st.top();
    st.pop();
    
    if(string("()[]").find(c2)+1==p) continue;
    
    cout << "no" << endl;
    return;
  }
  
  if(!st.empty())
    cout << "no" << endl;
  else
    cout << "yes"<< endl;
}

int main(){
  while(getline(cin,in) , in != ".") solve();
  
}