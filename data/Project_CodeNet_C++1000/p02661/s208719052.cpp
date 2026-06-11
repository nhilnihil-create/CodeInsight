#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
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
  vector<ll> l(n), r(n);
  rep(i, 0, n) cin >> l[i] >> r[i];

  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  if (n % 2 == 0) {
    cout << r[n / 2] + r[n / 2 - 1] - (l[n / 2] + l[n / 2 - 1]) + 1;
  } else {
    cout << r[n / 2] - l[n / 2] + 1;
  }
  return 0;
}