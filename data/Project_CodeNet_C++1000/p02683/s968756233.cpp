#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); i++)
#define repj(n) for (long long j = 0; j < (n); j++)
#define repk(n) for (long long k = 0; k < (n); k++)
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

ll c[20], a[20][20];
int main() {
  ll n, m, x;
  cin >> n >> m >> x;
  repi(n) {
    cin >> c[i];
    repj(m) cin >> a[i][j];
  }
  ll re = LLONG_MAX;
  repi(1ll << n) {
    vector<ll> xs(m, 0);
    ll cost = 0;
    repj(n) {
      if ((i >> j) & 1) {
        cost += c[j];
        repk(m) xs[k] += a[j][k];
      }
    }
    bool valid = true;
    repj(m) if (xs[j] < x) valid = false;
    if (valid) updatemin(re, cost);
  }
  cout << (re == LLONG_MAX ? -1 : re) << endl;
}
