#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  std::vector<vector<int>> v(n, std::vector<int>(n));
  rep(i,n) rep(j,n) v.at(i).at(j) = -1;
  rep(i,n) {
    int m; cin >> m;
    rep(j,m) {
      int x,y; cin >> x >> y;
      x--;
      // i番目の人がxに対してyという証言をした
      v[i][x] = y;
    }
  }
  int ans = 0;
  rep(bit,1<<n) {
    std::vector<int> d(n);
    rep(i,n) {
      if (bit>>i&1) d[i] = 1;
    }
    bool ok = true;
    rep(i,n) {
      if (d[i]) {
        rep(j,n) {
          if (v[i][j] == -1) continue;
          if (v[i][j] != d[j]) ok = false;
        }
      }
    }
    if (ok) ans = max(ans, __builtin_popcount(bit));
  }
  cout << ans << endl;
}
