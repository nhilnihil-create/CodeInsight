#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  int n, m; cin >> n >> m;
  vector<vector<int> > a(n+1, vector<int> (m+1));
  for (int i = 1; i <= n; ++i)
  for (int j = 1; j <= m; ++j) cin >> a[i][j];

  int ans = 0;
  for (int i = 1; i <= n; ++i)
  for (int op = i + 1; op <= n; ++op) {
    int t = 0;
    for (int j = 1; j <= m; ++j)
      t = t + (a[i][j] - a[op][j]) * (a[i][j] - a[op][j]);

    int st = sqrt(t);
    if (st * st == t) ++ans;
  }
  cout << ans;
  return 0;
}

