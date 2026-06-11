#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); ++i)
#define repj(n) for (long long j = 0; j < (n); ++j)
#define repk(n) for (long long k = 0; k < (n); ++k)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

ll p[100010], q[100100], r[100100], psum[100100], qsum[100100], rsum[100100];
int main() {
  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  repi(a) cin >> p[i];
  repi(b) cin >> q[i];
  repi(c) cin >> r[i];
  sort(p, p + a, greater<ll>());
  sort(q, q + b, greater<ll>());
  sort(r, r + c, greater<ll>());
  ll result = 0;
  repi(x) result += p[i];
  repi(y) result += q[i];
  ll pc = x - 1, qc = y - 1;
  repi(c) {
    ll pscore = pc >= 0 ? r[i] - p[pc] : -1;
    ll qscore = qc >= 0 ? r[i] - q[qc] : -1;
    if (pscore < 0 && qscore < 0) break;
    if (pscore > qscore) {
      result += pscore;
      --pc;
    } else {
      result += qscore;
      --qc;
    }
  }
  cout << result << endl;
}
