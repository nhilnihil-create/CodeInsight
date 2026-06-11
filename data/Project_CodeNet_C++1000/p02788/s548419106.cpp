#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define MP make_pair
#define F first
#define S second

const int INF = 2e9;

int main() {
  int n, d, a;
  cin >> n >> d >> a;
  vector<P> mon(n);
  rep(i, n) {
    int x, h;
    cin >> x >> h;
    mon[i] = MP(x, h);
  }
  sort(mon.begin(), mon.end());
  vector<int> imos(n+1, 0);
  ll ans = 0;
  rep(ib, n) {
    if (ib) imos[ib] += imos[ib-1];
    if (mon[ib].S <= (ll)imos[ib] * a) continue;
    int hp = mon[ib].S - imos[ib] * a;

    int l = mon[ib].F;
    int r = min((ll)l+2*d, (ll)INF);
    int ie = upper_bound(mon.begin(), mon.end(), MP(r, INF)) - mon.begin();

    int nb = (hp + a - 1) / a;
    imos[ib] += nb;
    imos[ie] -= nb;
    ans += nb;
  }
  cout << ans << endl;
  return 0;
}