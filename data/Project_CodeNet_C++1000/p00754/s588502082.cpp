#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  while(getline(cin,s),s!="."){
    stack<char> a;
    bool flag=false;
    for(int i=0;i<s.size();++i){
      if(s[i]=='(') a.push(s[i]);
      else if(s[i]=='[') a.push(s[i]);
      else if(s[i]==')')
        if(a.empty() || a.top()!='(') flag=true;
        else a.pop();
      else if(s[i]==']')
        if(a.empty() || a.top()!='[') flag=true;
        else a.pop();
      if(flag) break;
    }
    if(flag || !a.empty()) cout<<"no\n";
    else cout<<"yes\n";
  }
 
  return 0;
}