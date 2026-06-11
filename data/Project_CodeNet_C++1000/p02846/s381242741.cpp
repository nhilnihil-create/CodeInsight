#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v) do { x = max(x, v); } while(0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll t[2],a[2],b[2],c[2];

signed main() {
  rep(i,2) cin >> t[i];
  rep(i,2) cin >> a[i];
  rep(i,2) cin >> b[i];

  c[0] = a[0]*t[0] - b[0]*t[0];
  c[1] = a[1]*t[1] - b[1]*t[1];

  if (c[0]+c[1] == 0) {
    cout << "infinity" << endl;
    return 0;
  }

  if (c[0] < c[1]) {
    c[0] *= -1;
    c[1] *= -1;
  }

  if (c[0] > 0 && c[1] > 0 || c[0] < 0 && c[1] < 0) {
    cout << 0 << endl;
    return 0;
  }

  // 半周期ごとにc[0]、1周期ごとにc[1]だけずれていく
  c[1] += c[0];
  //printf("c[0]=%lld c[1]=%lld\n", c[0],c[1]);

  // 交わる周期数nは、c[0]/c[1] の切り上げ
  ll ans = 0;
  ll n = (c[0]-1) / (-c[1]) + 1;

  //cout << "n=" << n << endl;
  if (n <= 0) {
    cout << 0 << endl;
    return 0;
  }

  if (c[0] % (-c[1]) == 0) {
     ans =  n * 2;
  } else {
     ans =  n * 2 - 1;
  }
  cout << ans << endl;
  return 0;
}
