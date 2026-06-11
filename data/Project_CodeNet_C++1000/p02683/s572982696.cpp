#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const long double PI = 3.14159265358979323846264338327950L;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> c(n);
  rep(i, n) {
    cin >> c[i];
    rep(j, m) {
      cin >> a[i][j];
    }
  }
  int ans = 10000000;
  rep(i, 1<<n) {
    int cost = 0;
    vector<int> level(m);
    rep(j, n) {
      if((i>>j)&1) {
        cost += c[j];
        rep(k, m) {
          level[k] += a[j][k];
        }
      }
    }
    bool flag = true;
    rep(k, m) {
      if(level[k] < x) flag = false;
    }
    if(flag) {
      ans = min(ans, cost);
    }
  }
  if(ans == 10000000) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
        