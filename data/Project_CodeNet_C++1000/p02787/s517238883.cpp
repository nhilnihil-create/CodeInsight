#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

pair<ll, ll> m[10100];
ll ans_[10001];
ll n;
ll ans(ll h) {
  if (h <= 0) return 0;
  if (ans_[h] >= 0) return ans_[h];
  ll result = LLONG_MAX;
  rep(i, n) updatemin(result, m[i].second + ans(h - m[i].first));
  return ans_[h] = result;
}
int main() {
  ll h;
  cin >> h >> n;
  rep(i, n) cin >> m[i].first >> m[i].second;
  rep(i, 10001) ans_[i] = -1;
  cout << ans(h) << endl;
}
