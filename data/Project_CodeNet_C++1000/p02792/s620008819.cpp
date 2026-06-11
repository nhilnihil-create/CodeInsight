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
  int N;
  cin >> N;
  long long cnt[10][10];
  for (int i = 1; i <= 9; i++) fill(cnt[i], cnt[i] + 10, 0);
  for (int i = 1; i <= N; i++) {
    int s = i % 10;
    if (s == 0) continue;
    int p = i;
    while (p >= 10) p /= 10;
    cnt[p][s]++;
  }
  long long ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      ans += cnt[i][j] * cnt[j][i];
    }
  }
  cout << ans << "\n";
  return 0;
}
