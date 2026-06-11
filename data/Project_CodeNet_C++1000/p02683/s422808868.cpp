/*input
3 3 10
60 2 2 4
70 8 7 9
50 2 3 9
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
int n, m, x;
vector<int> c;
vector<vector<int>> a;
vector<int> sum;

bool ok() {
  rep(i, m) if (sum[i] < x) return false;
  return true;
}

int dfs(int i=0, int co=0) {
  if (i == n) {
    if (ok()) {
      // printf("%d\n", co);
      return co;
    }
    else {
      // printf("%d\n", co);
      return INF;
    }
  }
  int n1, n2;
  n1 = dfs(i+1, co);
  rep(j, m) sum[j] += a[i][j];
  n2 = dfs(i+1, co+c[i]);
  int res = min(n1, n2);
  rep(j, m) sum[j] -= a[i][j];
  return res;
}

int main() {
  cin >> n >> m >> x;
  c.resize(n);
  a.resize(n, vector<int>(m));
  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }
  sum.resize(m, 0);
  int ans = dfs();
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}