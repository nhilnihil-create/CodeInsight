#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  int n;
  cin >> n;

  vector<int> ans(n + 1);
  auto f = [](int x, int y, int z) {
    return x * x + y * y + z * z + x * y + y * z + z * x;
  };
  rep(x, 1, sqrt(n)) rep(y, 1, sqrt(n)) rep(z, 1, sqrt(n)) {
    int v = f(x, y, z);
    if (v <= n) ans[v]++;
  }
  rep(i, 1, n + 1) cout << ans[i] << '\n';

#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}