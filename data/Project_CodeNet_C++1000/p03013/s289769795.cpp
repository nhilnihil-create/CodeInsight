#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int n, m;
ll a[100010];
ll dp[100010];

int main() {
  cin >> n >> m;
  rep(i, m) cin >> a[i];
  vector<int> x(n + 1, false);
  rep(i, m) x[a[i]] = true;
  rep(i, 100010) dp[i] = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (x[i]) continue;
    dp[i] += dp[i - 1];
    if (i >= 2) dp[i] += dp[i - 2];
    dp[i] %= MOD;
  }
  cout << dp[n] << endl;
  return 0;
}
