#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(q), b(q), c(q), d(q);
  rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  ll ans = 0;

  int NM = n + m - 1;

  rep(A, 1 << NM) {
    ll sumd = 0;
    rep(qi, q) {
      int ai = a[qi];
      int bi = b[qi];
      int an = 0;
      int am = 1;
      int av = 0;
      int bv = 0;

      for (int i = 1; i <= NM; i++) {
        if (A >> i & 1) {
          am++;
        } else {
          an++;
          if (an == ai) av = am;
          if (an == bi) bv = am;
        }
      }
      if (an == n && c[qi] == bv - av) sumd += d[qi];
    }

    ans = max(ans, sumd);
  }
  cout << ans << endl;

  return 0;
}