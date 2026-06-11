#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n, i) for(ll i = 0; i < n; ++i)

const ll MOD = 1e9+7;

void solve(){
  ll n, m; cin >> n >> m;
  vector<bool> damaged(n+1, false);
  rep(m, i) {
    ll ta; cin >> ta;
    damaged[ta] = true;
  }

  vector<ll> dp(n+1, 0);
  dp[0] = 1;
  if (!damaged[1]) dp[1] = 1;

  for(ll i = 2; i <= n; ++i) {
    if (!damaged[i-1]) dp[i] += dp[i-1];
    if (!damaged[i-2]) dp[i] += dp[i-2];
    dp[i] %= MOD;
  }

  cout << dp[n] << endl;
}

int main() {
  solve();
  return 0;
}