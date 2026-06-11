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
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  string fr, ba;
  bool flip = false;
  while (Q--) {
    int T;
    cin >> T;
    if (T == 1)
      flip = !flip;
    else {
      int F;
      char C;
      cin >> F >> C;
      if ((F & 1) ^ flip)
        fr += C;
      else
        ba += C;
    }
  }
  string ans;
  if (flip) {
    reverse(S.begin(), S.end());
    reverse(ba.begin(), ba.end());
    ans = ba + S + fr;
  } else {
    reverse(fr.begin(), fr.end());
    ans = fr + S + ba;
  }
  cout << ans << endl;
  return 0;
}
