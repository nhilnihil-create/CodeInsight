#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

int main() {
  ll H, W, m;
  cin >> H >> W >> m;
  vector<ll> h(m), w(m), hs(H), ws(W);
  rep(i, m) {
    cin >> h[i] >> w[i];
    --h[i];
    --w[i];
    ++hs[h[i]];
    ++ws[w[i]];
  }
  using pll = pair<ll, ll>;
  set<pll> s;
  rep(i, m) s.emplace(h[i], w[i]);
  ll hsmax = -1, wsmax = -1;
  itr(x, hs) updatemax(hsmax, x);
  itr(x, ws) updatemax(wsmax, x);
  vector<ll> hsmaxi, wsmaxi;
  rep(i, H) if (hs[i] == hsmax) hsmaxi.push_back(i);
  rep(i, W) if (ws[i] == wsmax) wsmaxi.push_back(i);
  ll ans = hsmax + wsmax;
  if (hsmaxi.size() * wsmaxi.size() <= m) {
    itr(hi, hsmaxi) itr(wi, wsmaxi) {
      if (s.find(pll(hi, wi)) == s.end()) goto end;
    }
    --ans;
  }
end:
  cout << ans << endl;
}
