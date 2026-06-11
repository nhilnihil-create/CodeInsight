#include <bits/stdc++.h>
#define lol long long
template<class A,class B>inline bool chmax(A &a,const B &b){return(b>a&&(a=b,true));}
template<class A,class B>inline bool chmin(A &a,const B &b){return(b<a&&(a=b,true));}
using namespace std;
lol mod=1e9+7;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;
  cin >>n>>m;
  vector<int> cost(m),key(m,0);
  for(int i=0;i<m;i++){
    int a,b;
    cin >>a>>b;
    cost[i]=a;
    while(b--){
      int c;cin >>c;
      key[i]|=(1<<(c-1));
    }
  }
  vector<lol> dp(1<<n,mod);
  dp[0]=0;
  for(int i=0;i<m;i++){
    for(int bit=0;bit<(1<<n);bit++){
      chmin(dp[bit|key[i]],dp[bit]+cost[i]);
    }
  }
  if(dp[(1<<n)-1]==mod) cout <<"-1\n";
  else cout <<dp[(1<<(n))-1]<<'\n';
  return (0);
}