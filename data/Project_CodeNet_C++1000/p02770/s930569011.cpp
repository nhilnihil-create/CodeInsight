#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e4+10;

int d[N*2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, q; cin >> k >> q;
  for (int i = 0; i < k; i++) {
    cin >> d[i];
  }
  int nk = k;
  while (nk < N) nk += k;
  for (int i = k; i < nk; i++) {
    d[i] = d[i%k];
  }
  k = nk;
  while (q--) {
    int n, x, m; cin >> n >> x >> m;
    n--;
    x %= m;
    ll tot = 0;
    int zcnt = 0;
    for (int i = 0; i < k; i++) {
      tot += (d[i] % m);
      zcnt += (d[i] % m == 0);
    }
    int num_cyc = n / k, rem_cyc = n % k;
    ll ans = num_cyc * k - (x + tot * num_cyc) / m - num_cyc * zcnt;
    //cout << ans << nl;
    x = (x + tot * num_cyc) % m;
    for (int i = 0; i < rem_cyc; i++) {
      int nx = (x + d[i]) % m;
      //cerr << x << " " << nx << nl;
      ans += (x < nx);
      x = nx;
    }
    cout << ans << nl;
  }
}
