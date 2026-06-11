#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v)                                                            \
  do {                                                                         \
    x = max(x, v);                                                             \
  } while (0)
#define chmin(x, v)                                                            \
  do {                                                                         \
    x = min(x, v);                                                             \
  } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll k, q;
vector<ll> d;

signed main() {
  cin >> k >> q;
  d.resize(k);
  rep(i, k) {
    cin >> d[i];
  }
  rep(t, q) {
    ll n, x, m;
    cin >> n >> x >> m;
    x %= m;
    vector<ll> dd(k);
    rep(i, k)
      dd[i] = d[i] % m;

    // cout << "x: " << x << endl;
    // cout << "dd: ";
    // rep(i, k){
    //   cout << dd[i] << " ";
    // }
    // cout << endl;

    ll B=0;
    rep(i, k) {
      if (dd[i] != 0)
        continue;
      ll p = (n - (i+1) + (k-1))/k;
      // printf("# i=%d n=%d\n", i, p);
      B += p;
    }

    ll an_1 = x;
    rep(i, k) {
      an_1 += dd[i] * ((n - (i+1) + (k-1))/k);
    }
    ll C = an_1/m - x/m;

    ll ans = (n-1) -B -C;
    // printf("B=%ld C=%ld\n", B, C);
    cout << ans << endl;
  }
}
