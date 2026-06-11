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
    for(int j=0;j<b;j++){
      int c;cin >>c;
      c--;
      key[i]|=(1<<c);
    }
  }
  vector<vector<lol> > dp(m+1,vector<lol>(1<<n,mod));
  dp[0][0]=0;
  for(int i=0;i<m;i++){
    for(int bit=0;bit<(1<<n);bit++){
      chmin(dp[i+1][bit],dp[i][bit]);
      chmin(dp[i+1][bit|key[i]],dp[i][bit]+cost[i]);
    }
  }
  if(dp[m][(1<<n)-1]==mod) cout <<"-1\n";
  else cout <<dp[m][(1<<(n))-1]<<'\n';
  return (0);
}