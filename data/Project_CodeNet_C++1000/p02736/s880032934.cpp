#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define debugArray(x, n)                                      \
  cerr << __LINE__ << ": " << #x << " = {";                   \
  for (long long hoge = 0; (hoge) < (long long)(n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];                   \
  cerr << "}" << '\n'
#define debugMatrix(x, h, w)                                         \
  cerr << __LINE__ << ": " << #x << " =\n";                          \
  for (long long hoge = 0; (hoge) < (long long)(h); ++(hoge)) {      \
    cerr << ((hoge ? " {" : "{{"));                                  \
    for (long long fuga = 0; (fuga) < (long long)(w); ++(fuga))      \
      cerr << ((fuga ? ", " : "")) << x[hoge][fuga];                 \
    cerr << "}" << (hoge + 1 == (long long)(h) ? "}" : ",") << '\n'; \
  }
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#define debugMatrix(x, h, w) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  auto nCr_mod2 = [](int n, int r) {
    int ret = 1;
    while (n) {
      ret &= (r & 1) <= (n & 1);
      n >>= 1, r >>= 1;
    }
    return ret;
  };
  int N;
  cin >> N;
  string s;
  cin >> s;
  int a[N - 1];
  for (int i = 0; i < N - 1; i++) a[i] = abs(s[i] - s[i + 1]);
  bool one = false;
  for (int i = 0; i < N - 1; i++) one |= a[i] == 1;
  int ans = 0;
  if (one) {
    for (int i = 0; i < N - 1; i++)
      if (a[i] == 1) ans ^= nCr_mod2(N - 2, i);
  } else {
    for (int i = 0; i < N - 1; i++)
      if (a[i] == 2) ans ^= nCr_mod2(N - 2, i);
    ans *= 2;
  }
  cout << ans << '\n';
  return 0;
}
