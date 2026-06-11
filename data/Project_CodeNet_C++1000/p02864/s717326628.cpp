#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=309;
int h[N];
int n,K;
ll dp[N][N];
int main(){
  cin>>n>>K;
  for(int i=1;i<=n;i++)cin>>h[i];
  memset(dp,0x3f,sizeof(dp));
  dp[0][0]=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      for(int k=0;k<i;k++){
        dp[i][j]=min(dp[i][j],dp[k][j-1]+max(0,h[i]-h[k]));
      }
  ll ans=0x3f3f3f3f3f3f3f3f;
  for(int i=0;i<=n;i++)ans=min(ans,dp[i][n-K]);
  cout<<ans<<endl;
  return 0;
}
