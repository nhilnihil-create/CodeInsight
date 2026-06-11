#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main(){
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i,n) {
    cin >> c[i];
    rep(j,m) {
      cin >> a[i][j];
    }
  }
  int ans = INF;
  rep(bi, 1<<n) {
    vector<int> u(m);
    int tp = 0;
    rep(i,n) {
      if (bi>>i & 1) {
        rep(j,m) u[j] += a[i][j];
        tp += c[i];
      }
    }
    bool can = true;
    rep(i,m) {
      if (u[i] < x) can = false;
    }
    if (can) ans = min(ans, tp);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}