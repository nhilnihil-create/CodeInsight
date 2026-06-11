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
  long long K;
  cin >> K;
  if (K % 2 == 0 || K % 5 == 0) {
    cout << -1 << endl;
  } else {
    int ans;
    long long sum = 0;
    for (ans = 1; ans <= K; ans++) {
      sum = (sum * 10 + 7) % K;
      if (sum == 0) break;
    }
    cout << ans << endl;
  }
  return 0;
}
