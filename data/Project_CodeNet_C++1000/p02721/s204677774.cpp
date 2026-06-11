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
  int N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;
  int dpl[N + 1], dpr[N + 1];
  dpl[0] = 0;
  for (int i = 1; i <= N; i++) {
    dpl[i] = dpl[i - 1];
    if (S[i - 1] == 'o') {
      int tmp = 0;
      if (i >= C + 1) tmp = dpl[i - C - 1];
      dpl[i] = max(dpl[i], tmp + 1);
    }
  }
  debugArray(dpl, N + 1);
  dpr[N] = 0;
  for (int i = N - 1; i >= 0; i--) {
    dpr[i] = dpr[i + 1];
    if (S[i] == 'o') {
      int tmp = 0;
      if (i + C + 1 <= N) tmp = dpr[i + C + 1];
      dpr[i] = max(dpr[i], tmp + 1);
    }
  }
  debugArray(dpr, N + 1);
  for (int k = 0; k < N; k++) {
    if (S[k] == 'x') continue;
    if (dpl[k] + dpr[k + 1] >= K) continue;
    cout << k + 1 << endl;
  }
  return 0;
}
