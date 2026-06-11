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
  long long N, K;
  cin >> N >> K;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i], A[i]--;
  int to[80][N];
  for (int i = 0; i < N; i++) to[0][i] = A[i];
  for (int k = 1; k < 80; k++) {
    for (int i = 0; i < N; i++) {
      to[k][i] = to[k - 1][to[k - 1][i]];
    }
  }
  int ans = 0;
  for (int j = 63; j >= 0; j--) {
    if ((K >> j) & 1) ans = to[j][ans];
  }
  cout << ans + 1 << endl;
  return 0;
}
