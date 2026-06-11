#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n,h;
  cin >> h >> n;
  int a[n],b[n];
  rep(i,n)cin >> a[i] >> b[i];
  int m = 2*10010;
  int dp[n+1][m+1];
  rep(i,n+1)rep(j,m+1)dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i,n){
    rep(j,m){
      if(j<a[i])dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = min(dp[i+1][j-a[i]]+b[i],min(dp[i+1][j],dp[i][j]));
    }
  }
  int ans = INF;
  rep(i,m+1)if(dp[n][i] < ans && i>=h)ans = dp[n][i];
  cout << ans << endl;
  return 0;
}