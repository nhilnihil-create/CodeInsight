#include <iostream>
using namespace std;

const int64_t MOD = 998244353;

int main() {
  int n, s;
  cin >> n >> s;
  int64_t dp[n + 1][s + 1];
  dp[0][0] = 1;
  for (int i = 1; i <= s; ++i) {
    dp[0][i] = 0;
  }
  for (int i = 1, a; cin >> a; ++i) {
    for (int j = s; j >= 0; --j) {
      dp[i][j] = (2 * dp[i - 1][j] + (j >= a ? dp[i - 1][j - a] : 0)) % MOD;
    }
  }
  cout << dp[n][s];
  return 0;
}
