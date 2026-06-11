#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second 
signed main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m,a;
  int dp[1000000]={};
  cin>>n>>m;
  dp[0]=1;
  dp[1]=1;
  for(int i=0;i<m;i++){
    cin>>a;
    dp[a]=-1;
  }
  for(int i=2;i<=n;i++){
    if(dp[i]!=-1){
      if(dp[i-1]!=-1) dp[i]+=dp[i-1];
      if(dp[i-2]!=-1) dp[i]+=dp[i-2];
      dp[i]%=1000000007;
    }
  }
  cout<<dp[n]<<"\n";
}
