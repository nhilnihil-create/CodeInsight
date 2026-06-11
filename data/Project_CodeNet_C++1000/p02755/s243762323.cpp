#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                             \
  cerr << __LINE__ << ": " << #x << " = {";          \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) { \
    cerr << ((hoge) ? "," : "") << x[hoge];          \
  }                                                  \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A, B;
  cin >> A >> B;
  int ans;
  for (ans = 1; ans <= 10000; ans++)
    if (ans * 8 / 100 == A && ans * 10 / 100 == B) break;
  if (ans > 10000) ans = -1;
  cout << ans << endl;
  return 0;
}
