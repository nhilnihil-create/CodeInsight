#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const ll mod = 998244353;

int main(){
  int n, s;
  cin >> n >> s;
  vector<vector<ll>> dp(n, vector<ll> (3005));  
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  dp[0][0] = 2; dp[0][a[0]] = 1;
  rep(i, n-1){
    rep(j, s+1){
      dp[i+1][j] = dp[i][j]*2 % mod;
      if( j >= a[i+1] ) dp[i+1][j] = (dp[i+1][j] + dp[i][j-a[i+1]]) % mod;
      }
    }
  ll ans = dp[n-1][s];
  cout << ans << endl;
  return 0;
}
