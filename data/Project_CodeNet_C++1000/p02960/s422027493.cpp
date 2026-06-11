#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

constexpr ll MOD = 1000000007;

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<ll> dp(13);
  dp[0] = 1;

  rep(i, 0, n) {
    decltype(dp) next(13);
    rep(j, 0, 13) {
      if (s[i] == '?') {
        rep(k, 0, 10)(next[(j * 10 + k) % 13] += dp[j]) %= MOD;
      } else {
        int x = s[i] - '0';
        (next[(j * 10 + x) % 13] += dp[j]) %= MOD;
      }
    }
    dp = next;
  }

  cout << dp[5] << endl;
  return 0;
}