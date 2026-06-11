#include <iostream>
#include <cstdio>

using namespace std;

uint64_t dp[2010][2010] = {};

int main() {
  uint64_t s;
  cin >> s;
  uint64_t ss = s / 3 + 1;
  const uint64_t mod = 1'000'000'007;
  uint64_t sum = 0;
  dp[0][0] = 1;
  for (uint64_t i = 1; i <= ss; ++i) {
    for (uint64_t j = 3; j <= s; ++ j) {
      dp[i][j] = (dp[i-1][j-3] + dp[i][j-1]) % mod;
    }
    sum = (sum + dp[i][s]) % mod;
  }

  cout << sum << endl;
}
