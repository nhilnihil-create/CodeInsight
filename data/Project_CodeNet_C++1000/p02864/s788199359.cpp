#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll INF = 1e18;

int main(){
  ll n, k;
  cin >> n >> k;
  ll h[n+1];
  h[0] = 0;
  rep(i,n) cin >> h[i+1];
  vector<vector<ll>> dp(n+1,vector<ll>(n+1,INF));
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      rep(k,i) {  
        dp[i][j] = min(dp[i][j],dp[k][j-1]+max((ll)0,h[i]-h[k]));
      }
    }
  }
  ll ans = INF;
  rep(i,n+1) ans = min(ans,dp[i][n-k]);
  cout << ans << endl;
  return 0;
}
