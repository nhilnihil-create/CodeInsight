#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];

  vector<int> d(n+2, 0);
  rep(i, m) d[a[i]] = 1;
  d[n+1] = 1;

  vector<int> dp(n+1, 0);
  dp[0] = 1;

  rep(i, n) {
    if (d[i+1] == 0) dp[i+1] = (dp[i+1] + dp[i]) % MOD;
    if (d[i+2] == 0) dp[i+2] = (dp[i+2] + dp[i]) % MOD;
  }
  cout << dp[n] << endl;
  return 0;
}