#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s,t;
  cin>>s>>t;
  int i,cnt=0;
  for(i=0; i<s.size(); ++i) if(s[i]==t[i]) ++cnt;
  if(cnt==s.size()) cout<<"Yes"<<endl; else cout<<"No"<<endl;
  return 0;
}
