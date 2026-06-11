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
  int n, k;
  cin >> n >> k;
  vi a(n);
  rep(i, n) cin >> a[i];
  dump(a);
  rep(j, k) {
    vi b(n);
    vi f(n + 1);
    rep(i, n) {
      f[max(0, i - a[i])]++;
      f[min(n, i + a[i] + 1)]--;
    }
    dump(f);
    rep(i, n) b[i] = i == 0 ? f[i] : b[i - 1] + f[i];
    dump(b);
    if (a == b) break;
    a = b;
  }
  rep(i, n) cout << a[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}