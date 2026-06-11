#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  rep(i, 0, a) cin >> p[i];
  rep(i, 0, b) cin >> q[i];
  rep(i, 0, c) cin >> r[i];
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());

  rep(i, 0, x) r.push_back(p[i]);
  rep(i, 0, y) r.push_back(q[i]);

  sort(r.rbegin(), r.rend());
  ll ans = 0;
  rep(i, 0, x + y) ans += r[i];
  cout << ans << endl;
  return 0;
}