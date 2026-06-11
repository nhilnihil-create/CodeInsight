#include <bits/stdc++.h>

// #LIB#

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
  ll n;
  cin >> n;
  vector<ll> w(n);
  rep(i, n) cin >> w[i];
  vector<ll> ws(n + 1);
  rep(i, n) ws[i + 1] = ws[i] + w[i];
  ll ans = LLONG_MAX;
  repr(i, 1, n) updatemin(ans, abs(ws[i] - (ws[n] - ws[i])));
  cout << ans << endl;
}
