#include <iostream>
using namespace std;

const int64_t MOD = 998244353;

int main() {
  int n, s;
  cin >> n >> s;
  int64_t dp[s + 1];
  dp[0] = 1;
  for (int i = 1; i <= s; ++i) {
    dp[i] = 0;
  }
  for (int a; cin >> a; ) {
    for (int j = s; j >= 0; --j) {
      dp[j] = (2 * dp[j] + (j >= a ? dp[j - a] : 0)) % MOD;
    }
  }
  cout << dp[s];
  return 0;
}
