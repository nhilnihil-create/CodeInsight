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
  int N, M;
  cin >> N >> M;
  if (N & 1) {
    for (int i = 1; i <= M; i++) {
      cout << i << " " << N + 1 - i << endl;
    }
  } else {
    for (int i = 1, len = M & 1 ? M : M - 1; len >= 1; i++, len -= 2) {
      cout << i << " " << i + len << endl;
    }
    for (int i = N - 1, len = M & 1 ? M - 1 : M; len >= 2; i--, len -= 2) {
      cout << i << " " << i - len << endl;
    }
  }
  return 0;
}
