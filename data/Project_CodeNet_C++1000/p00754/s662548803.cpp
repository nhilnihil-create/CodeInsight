#include<bits/stdc++.h>
using namespace std;
main(){
  string s;
  while(getline(cin,s),s!="."){
    stack<char> a;
    int i=0;
    for(;i<s.size();++i){
      if(!(s[i]-'(')||!(s[i]-'['))a.push(s[i]);
      if(s[i]==')')if(a.empty()||a.top()!='(')break;else a.pop();
      if(s[i]==']')if(a.empty()||a.top()!='[')break;else a.pop();
    }cout<<(i!=s.size()||!a.empty()?"no":"yes")<<endl;
  }
}