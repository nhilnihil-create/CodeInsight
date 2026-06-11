#include <bits/stdc++.h>
#define inf (long long)1e13
using namespace std;

long long n, k;
vector<long long> h;
long long dp[500][500][500] = {0};

long long solve();

int main() {
  cin >> n >> k;
  h.resize(n);
  for(int i = 0; i < n; ++i) cin >> h[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = inf;
  for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= n; ++j)
      for(int l = 0; l <= k; ++l) dp[i][j][l] = inf;
  dp[0][0][k] = 0;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j <= i; ++j)
      for(int l = 0; l <= k; ++l) {
        // not use
        long long now = h[i];
        if(j > 0) now = max(0LL, h[i] - h[j - 1]);
        dp[i + 1][i + 1][l] =
            min(dp[i + 1][i + 1][l], dp[i][j][l] + now);
        // use
        if(l < k)
          dp[i + 1][j][l] =
              min(dp[i + 1][j][l], dp[i][j][l + 1]);
      }
  for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= k; ++j) ans = min(ans, dp[n][i][j]);
  return ans;
}
