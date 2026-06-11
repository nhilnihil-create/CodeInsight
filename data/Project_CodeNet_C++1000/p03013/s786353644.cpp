#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
  ll n, m;
  cin >> n >> m;

  vector<int> a(m);
  rep(i, m) cin >> a[i];

  vector<int> s(100010);
  rep(i, m) s[a[i]] = 1;

  vector<ll> dp(n + 3);
  dp[0] = 1;

  rep(i, n) {
    if (s[i + 1] != 1) {
      dp[i + 1] += dp[i];
      dp[i + 1] %= MOD;
    }
    if (s[i + 2] != 1) {
      dp[i + 2] += dp[i];
      dp[i + 1] %= MOD;
    }
  }
  cout << dp[n] << endl;
}
