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
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  --x, --y;
  vector<int> ans(n);
  rep(i, 0, n) rep(j, i + 1, n) {
    int mn = min(j - i, abs(x - i) + 1 + abs(y - j));
    ans[mn]++;
  }
  rep(i, 1, n) cout << ans[i] << '\n';

  return 0;
}