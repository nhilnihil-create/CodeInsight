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
  int H[N];
  for (int i = 0; i < N; i++) cin >> H[i];
  bool good[N];
  fill(good, good + N, true);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (H[a] <= H[b]) good[a] = false;
    if (H[b] <= H[a]) good[b] = false;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) ans += good[i];
  cout << ans << endl;
  return 0;
}
