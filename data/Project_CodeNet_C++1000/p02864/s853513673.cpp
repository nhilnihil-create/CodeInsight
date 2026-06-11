#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> h(n + 2, 0);
  for (int i = 0; i < n; i++) {
    cin >> h[i + 1];
  }
  vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < i + 1; j++) {
      for (int t = 0; t < j + 1; t++) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i - t][j - t] + max(0LL, h[i + 1] - h[i - t]));
      }
    }
  }
  cout << dp[n + 1][k] << endl;
}
