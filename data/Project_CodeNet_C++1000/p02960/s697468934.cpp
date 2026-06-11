#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1000000007;
int main() {
  string s;
  cin >> s;
  int sl = s.size();
  vector<vector<ll>> dp(sl + 1, vector<ll>(13, 0));
  dp[0][0] = 1;
  for (int i = 0; i < sl; ++i) {
    for (int j = 0; j < 13; ++j) {
      if (s[i] == '?') {
        for (int k = 0; k < 10; ++k) {
          (dp[i + 1][(j * 10 + k) % 13] += dp[i][j]) %= MOD;
        }
      } else {
        int k = s[i] - '0';
        (dp[i + 1][(j * 10 + k) % 13] += dp[i][j]) %= MOD;
      }
    }
  }
  cout << dp[sl][5] << endl;
  return 0;
}
