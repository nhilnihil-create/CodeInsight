#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

int main() {
  int n,m,x;
  cin >> n >> m >> x;
  std::vector<int> c(n);
  Graph a(n, std::vector<int>(m));
  rep(i,n) {
    cin >> c.at(i);
    rep(j,m) {
      cin >> a.at(i).at(j);
    }
  }
  ll ans = 1e18;
  rep(bit,1<<n) {
    std::vector<int> d(n);
    rep(i,n) {
      if (bit>>i&1) d[i] = 1;
    }
    ll cost = 0;
    std::vector<int> total(m);
    bool ok = true;
    rep(i,n) {
      if (d[i]) {
        cost += c[i];
        rep(j,m) {
          total[j] += a[i][j];
        }
      }
    }
    rep(j,m) if (total[j] < x) ok = false;
    if (ok) ans = min(ans, cost);
  }
  if (ans == 1e18) cout << -1 << endl;
  else cout << ans << endl;
}
