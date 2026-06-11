#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
#define mins(x, y) (x = min(x, y))
#define maxs(x, y) (x = max(x, y))
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

void solve() {
  vl t(2), a(2), b(2);
  cin >> t[0] >> t[1];
  cin >> a[0] >> a[1];
  cin >> b[0] >> b[1];
  rep(i, 2) {
    a[i] *= t[i];
    b[i] *= t[i];
    if (a[i] > b[i]) {
      a[i] -= b[i];
      b[i] = 0;
    } else {
      b[i] -= a[i];
      a[i] = 0;
    }
  }
  dump(t, a, b);
  int za = (a[0] == 0 && a[1] == 0) ? 1 : 0;
  int zb = (b[0] == 0 && b[1] == 0) ? 1 : 0;
  if (za && zb) {
    cout << "infinity" << endl;
    return;
  } else if (za || zb) {
    cout << 0 << endl;
    return;
  }
  ll cnt = 0;
  if (a[0] == 0 && b[0] == a[1]) {
    cout << "infinity" << endl;
    return;
  }
  if (a[0] == 0 && b[0] > a[1]) {
    cout << 0 << endl;
    return;
  }
  if (b[0] == 0 && a[0] == b[1]) {
    cout << "infinity" << endl;
    return;
  }
  if (b[0] == 0 && a[0] > b[1]) {
    cout << 0 << endl;
    return;
  }
  if (a[0] == 0) {
    ll delta = a[1] - b[0];
    dump("a[0]==0", b[0], a[1], delta);
    cnt = b[0] / delta * 2;
    if (b[0] % delta) cnt++;
    dump(cnt);
  }
  if (b[0] == 0) {
    dump("b[0]==0");
    ll delta = b[1] - a[0];
    cnt = a[0] / delta * 2;
    if (a[0] % delta) cnt++;
    dump(cnt);
  }
  cout << cnt << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}