#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  ll k, q;
  cin >> k >> q;
  vector<ll> d(k);
  rep(i, k) cin >> d[i];
  vector<ll> n(q), x(q), m(q);
  rep(i, q) cin >> n[i] >> x[i] >> m[i];

  rep(i, q) {
    vector<ll> dd = d;
    rep(j, k) {
      dd[j] %= m[i];
      if (dd[j] == 0) dd[j] = m[i];
      if (j) dd[j] += dd[j - 1];
    }
    x[i] %= m[i];
    ll sum = x[i] + dd[k - 1] * ((n[i] - 1) / k);
    if ((n[i] - 1) % k != 0) sum += dd[(n[i] - 1) % k - 1];
    cout << n[i] - 1 - sum / m[i] << endl;
  }




  
  return 0;
}