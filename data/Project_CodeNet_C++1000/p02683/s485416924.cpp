#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i,n) {
      cin >> c[i];
      rep(j,m) cin >> a[i][j];
    }
    int ans = INF;
    rep(is,1<<n) {
      vector<int> algo(m);
      int cost = 0;
      rep(i,n) {
        if (is>>i&1) {
          rep(j,m) algo[j] += a[i][j];
          cost += c[i];
        }
      }
      bool t = true;
      rep(i,m) {
        if (algo[i] < x) t = false;
      }
      if (t) ans = min(ans, cost);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}