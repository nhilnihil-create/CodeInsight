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
  long long L[N];
  for (int i = 0; i < N; i++) cin >> L[i];
  sort(L, L + N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      debug(make_pair(i, j));
      long long a = lower_bound(L, L + N, L[i] + L[j]) - (L + j + 1);
      debug(a);
      ans += a;
    }
  }
  cout << ans << '\n';
  return 0;
}
