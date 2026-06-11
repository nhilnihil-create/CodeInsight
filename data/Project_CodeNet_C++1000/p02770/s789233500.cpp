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

int64_t dceil(int64_t, int64_t);
int64_t dfloor(int64_t, int64_t);

int64_t dceil(int64_t x, int64_t y) {
  if (y < 0) {
    return dceil(-x, -y);
  }
  if (x < 0) {
    return -dfloor(-x, y);
  }
  return (x + y - 1) / y;
}

int64_t dfloor(int64_t x, int64_t y) {
  if (y < 0) {
    return dfloor(-x, -y);
  }
  if (x < 0) {
    return -dceil(-x, y);
  }
  return x / y;
}

int main() {
  int64_t k, q;
  cin >> k >> q;

  vector<int64_t> d(k);
  rep(i, k) { cin >> d[i]; }

  rep(i, q) {
    int64_t n, x, m;
    cin >> n >> x >> m;

    vector<int64_t> drem(k + 1), cnt(k + 1);
    drem[0] = 0;
    cnt[0] = 0;
    rep(j, k) {
      drem[j + 1] = d[j] % m;
      cnt[j + 1] = (drem[j + 1] == 0 ? 1 : 0);

      drem[j + 1] += drem[j];
      cnt[j + 1] += cnt[j];
    }

    int64_t eqcnt = ((n - 1) / k) * cnt[k] + cnt[(n - 1) % k];

    int64_t y = x + ((n - 1) / k) * drem[k] + drem[(n - 1) % k];
    int64_t s = dfloor(x, m) + 1;
    int64_t t = dfloor(y, m);
    int64_t gtcnt = t - s + 1;

    int64_t result = (n - 1) - eqcnt - gtcnt;
    cout << result << endl;
  }
  return 0;
}