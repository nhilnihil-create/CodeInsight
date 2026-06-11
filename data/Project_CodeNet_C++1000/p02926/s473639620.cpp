#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  vector<pair<long double, long double>> p(N);
  rep(i,N)
    cin >> p[i].first >> p[i].second;

  sort(begin(p), end(p), [](const auto &l, const auto &r) {
        auto lv = atan2l(l.second, l.first);   
        auto rv = atan2l(r.second, r.first);   
        return lv < rv;
      });

  rep(i, N) {
    p.push_back(p[i]);
  }

  double ans = 0.0;
  rep(i, N) {
    double curx = 0, cury = 0;
    for (int j=i; j<i+N; j++) {
      curx += p[j].first;
      cury += p[j].second;
      ans = max(ans, curx*curx + cury*cury);
    }
  }
  printf("%.20f\n", sqrt(ans));
  return 0;
}
