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
  auto pw = [](long long x) { return x * x * x * x * x; };
  long long X;
  cin >> X;
  auto solve = [&]() {
    for (long long A = 1; pw(A) - pw(A - 1) <= X; A++) {
      long long tmp = pw(A) - X;
      int sgn = tmp > 0 ? 1 : -1;
      for (long long B = 0; pw(B) <= abs(tmp); B++) {
        if (pw(B) * sgn == tmp) return make_pair(A, B * sgn);
      }
    }
    return make_pair(0ll, 0ll);
  };
  long long A, B;
  tie(A, B) = solve();
  cout << A << " " << B << endl;
  return 0;
}
