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
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using P = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

void solve() {
  int n;
  cin >> n;
  vi a(n + 1);
  rep(i, n + 1) cin >> a[i];
  dump(a);
  vl mn(n + 1), mx(n + 1);
  mn[n] = a[n];
  mx[n] = a[n];
  rep(i, n) {
    int j = n - i - 1;
    mn[j] = (mn[j + 1] + 1) / 2 + a[j];
    mx[j] = mx[j + 1] + a[j];
  }
  dump(mn, mx);
  if (1 < mn[0]) {
    cout << -1 << endl;
    return;
  }
  ll cnt = 1;
  ll b = 1;
  rep(i, n) {
    int j = i + 1;
    b *= 2;
    mins(b, mx[j]);
    cnt += b;
    b -= a[j];
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