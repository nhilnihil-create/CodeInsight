#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s; cin>>s;
  int res=0,sz=s.size()-1;
  for(int i=0; i<sz; ++i) if(s[i]!=s[sz-i]) ++res,s[i]=s[sz-i];
  cout<<res;
  return 0;
}
