#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1000000;
const int MOD = 1000000007;

signed main() {
int n,k;
cin>>n>>k;
int h[n+1];
h[0]=0;
for(int i=1;i<n+1;i++)cin>>h[i];
int dp[n+1][k+1];
for(int i=1;i<=n;i++)fill(dp[i],dp[i]+k+1,MOD*MOD);
fill(dp[0],dp[0]+k+1,0);
for(int i=1;i<=n;i++){
  for(int j=0;j<i;j++){
    for(int p=0;p+i-j-1<=k;p++){
      dp[i][p+i-j-1]=min(dp[i][p+i-j-1],dp[j][p]+max(0LL,h[i]-h[j]));
    }
  }
}
int ans=dp[n][k];
for(int i=1;n-i>=0&&k-i>=0;i++)ans=min(ans,dp[n-i][k-i]);

cout<<ans;
return 0;



}
