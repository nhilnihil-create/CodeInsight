#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    vector<vector<long long>> dp(n + 1);
    dp[n].push_back(0);
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        dp[i] = dp[i + 1];
        dp[i].push_back(a[i]);
        int now = 0;
        for (int j = 0; j < 60; j++) {
          bool swp = false;
          for (int k = now; k < (int) dp[i].size(); k++) {
            if (dp[i][k] & 1ll << j) {
              swap(dp[i][now], dp[i][k]);
              swp = true;
              break;
            }
          }
          if (!swp) {
            continue;
          }
          for (int k = 0; k < (int) dp[i].size(); k++) {
            if (k == now) {
              continue;
            }
            if (dp[i][k] & 1ll << j) {
              dp[i][k] ^= dp[i][now];
            }
          }
          now += 1;
        }
        dp[i].resize(now);
      } else {
        long long x = a[i];
        for (int j = 0; j < (int) dp[i + 1].size(); j++) {
          int k = 0;
          for (int l = 0; l < 60; l++) {
            if (dp[i + 1][j] & 1ll << l) {
              k = l;
              break;
            }
          }
          if (x & 1ll << k) {
            x ^= dp[i + 1][j];
          }
        }
        if (x == 0) {
          dp[i] = dp[i + 1];
        } else {
          break;
        }
      }
    }
    if ((int) dp[0].size() == 0) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}