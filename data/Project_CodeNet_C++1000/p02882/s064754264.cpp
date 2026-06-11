#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b, x;
  cin >> a >> b >> x;
  auto f = [&](long double theta) {
    if (a * tan(theta) < b) {
      return (b - a * tan(theta) / 2) * a * a;
    } else {
      return b * b * a / tan(theta) / 2;
    }
  };
  auto to_rad = [](long double theta) { return acos(-1) / 180 * theta; };
  long double low = 0, high = 90;
  for (int i = 0; i < 100; i++) {
    long double mid = (high + low) / 2;
    if (f(to_rad(mid)) < x) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << fixed << setprecision(12) << low << '\n';
  return 0;
}
