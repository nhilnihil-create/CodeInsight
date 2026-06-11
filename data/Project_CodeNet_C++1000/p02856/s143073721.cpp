#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
  function<pair<int, long long>(int, long long)> rec = [&](int d, long long n) {
    if (n == 1) return make_pair(d, 0ll);
    long long ret = n / 2;
    int D = 2 * d;
    if (D >= 10) {
      ret += n / 2;
      D = D % 10 + 1;
    }
    int DD;
    long long add;
    tie(DD, add) = rec(D, n / 2);
    ret += add;
    if (n & 1) {
      ret++;
      DD += d;
      if (DD >= 10) {
        ret++;
        DD = DD % 10 + 1;
      }
    }
    return make_pair(DD, ret);
  };
  int M;
  cin >> M;
  long long ans = -1;
  int cur = 0;
  for (int i = 0; i < M; i++) {
    int d;
    long long c;
    cin >> d >> c;
    int D;
    long long cnt;
    tie(D, cnt) = rec(d, c);
    ans += cnt + 1;
    cur += D;
    if (cur >= 10) {
      ans++;
      cur = cur % 10 + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
