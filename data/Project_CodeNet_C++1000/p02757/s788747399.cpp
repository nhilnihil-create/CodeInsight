#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int64_t MOD;

int64_t dpow(int64_t x, int64_t y) {
  if (y == 0) {
    return 1;
  }
  if (y % 2 == 0) {
    return dpow(x * x % MOD, y / 2);
  } else {
    return x * dpow(x, y - 1) % MOD;
  }
}

int64_t inv(int64_t x) { return dpow(x, MOD - 2); }

int main() {
  int N;
  cin >> N >> MOD;
  string s;
  cin >> s;

  int64_t result = 0;
  int d = 0;
  vector<int64_t> dp(MOD, 0);
  dp[0] = 1;
  rep(i, N) {
    d = 10 * d + (s[i] - '0');
    d %= MOD;

    if (MOD == 2 || MOD == 5) {
      result += (d % MOD == 0 ? i + 1 : 0);
    } else {
      int shift = dpow(10, i + 1);
      int key = d * inv(shift) % MOD;

      result += dp[key];
      dp[key]++;
    }
  }
  cout << result << endl;
  return 0;
}