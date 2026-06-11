#include <algorithm>
#include <bitset>
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

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)

int main() {
  int N;
  cin >> N;

  using P = pair<int, int>;
  vector<P> a(N);
  rep(i, N) {
    int v;
    cin >> v;
    a[i] = P(v, i);
  }

  sort(a.begin(), a.end());

  vector<vector<int64_t>> dp(
      N + 1, vector<int64_t>(N + 1, -1'000'000'000LL * 2'000 * 2'000));
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    int v, idx;
    tie(v, idx) = a[N - i];
    irep(j, i) {
      if (i - 1 - j >= 0) {
        chmax(dp[i][j],
              dp[i - 1][j] + (int64_t)v * (N - 1 - (i - 1 - j) - idx));
      }
      if (j - 1 >= 0) {
        chmax(dp[i][j], dp[i - 1][j - 1] + (int64_t)v * (idx - (j - 1)));
      }
    }
  }

  int64_t result = 0;
  irep(i, N) { chmax(result, dp[N][i]); }
  cout << result << endl;

  return 0;
}