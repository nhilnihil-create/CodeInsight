#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
const int M = 1e9 + 7;

int main(void){
  string s,t;cin>>s>>t;
  long long ans=0,cur=0,n=s.length(),m=t.length(),x;
  bool ok=true;
  vector<set<int>>vs(26);
  rep(i,26)vs[i].insert(M);
  rep(i,n)vs[s[i]-'a'].insert(i+1);
  rep(i,m){
    x=t[i]-'a';
    cur=*vs[x].upper_bound(cur);
    if(cur==M)++ans,cur=*vs[x].begin();
    if(cur==M)ok=false;
  }

  (ans*=n)+=cur;
  printf("%lld\n",ok?ans:-1);
  return 0;
}
