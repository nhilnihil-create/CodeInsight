#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
constexpr ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  rep(i, 3, n + 1) rep(j, 3, i + 1) dp[i] = (dp[i] + dp[i - j]) % MOD;
  cout << dp[n] << endl;
  return 0;
}
