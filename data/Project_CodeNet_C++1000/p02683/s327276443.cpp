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
  int N, M, X;
  cin >> N >> M >> X;
  int C[N];
  int A[N][M];
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    for (int j = 0; j < M; j++) cin >> A[i][j];
  }
  int ans = INT_MAX;
  for (int s = 0; s < (1 << N); s++) {
    int cost = 0;
    for (int i = 0; i < N; i++)
      if ((s >> i) & 1) cost += C[i];
    int skill[M];
    fill(skill, skill + M, 0);
    for (int i = 0; i < N; i++)
      if ((s >> i) & 1) {
        for (int j = 0; j < M; j++) skill[j] += A[i][j];
      }
    bool isok = true;
    for (int j = 0; j < M; j++) isok &= skill[j] >= X;
    if (isok) ans = min(ans, cost);
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << endl;
  return 0;
}
