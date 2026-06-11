#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
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
  int N;
  cin >> N;
  long double x[N], y[N];
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
  vector<int> p(N);
  iota(p.begin(), p.end(), 0);
  int cnt = 1;
  for (int i = 1; i <= N; i++) cnt *= i;
  long double ans = 0;
  for (int j = 0; j < cnt; j++) {
    long double dist = 0;
    for (int i = 0; i + 1 < N; i++) {
      long double dx = x[p[i + 1]] - x[p[i]];
      long double dy = y[p[i + 1]] - y[p[i]];
      dist += sqrt(dx * dx + dy * dy);
    }
    ans += dist;
    next_permutation(p.begin(), p.end());
  }
  ans /= cnt;
  cout << fixed << setprecision(12) << ans << '\n';
  return 0;
}
