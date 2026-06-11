#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr int INF = 0x3f3f3f3f;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int& a : x) cin >> a;

  int ans = INF;
  rep(i, 1, 101) {
    int cnt = 0;
    rep(j, 0, n) { cnt += (x[j] - i) * (x[j] - i); }
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}