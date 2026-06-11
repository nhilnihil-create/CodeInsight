#include<bits/stdc++.h>
using namespace std;
#define lol long long
signed main(){
  int n,m;
  cin >>n>>m;
  vector<int> a(m),key(m);
  for(int i=0;i<m;i++){
    int b;cin >>a[i]>>b;
    for(int j=0;j<b;j++){
      int c;
      cin >>c;
      key[i]|=1<<(c-1);
    }
  }
  vector<vector<int>> dp(m+2,vector<int>(1<<n,1e9));
  dp[0][0]=0;
  for(int i=0;i<m;i++){
    for(int bit=0;bit<(1<<n);bit++){
      dp[i+1][bit]=min(dp[i+1][bit],dp[i][bit]);
      dp[i+1][bit|key[i]]=min(dp[i+1][bit|key[i]],dp[i][bit]+a[i]);
    }
  }
  if(dp[m][(1<<n)-1]!=1e9) cout <<dp[m][(1<<n)-1]<<'\n';
  else cout <<"-1\n";
  return(0);
}