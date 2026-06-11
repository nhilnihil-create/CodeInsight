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
  long double A, B, H, M;
  cin >> A >> B >> H >> M;
  const long double PI = acos(-1);
  long double ans
      = sqrt(A * A + B * B
             - 2 * A * B * cos(2 * PI * (H / 12 + M / 12 / 60 - M / 60)));
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}
