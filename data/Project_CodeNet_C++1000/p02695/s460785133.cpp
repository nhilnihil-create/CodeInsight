/*input
4 6 10
2 4 1 86568
1 4 0 90629
2 3 0 90310
3 4 1 29211
3 4 3 78537
3 4 2 8580
1 2 1 96263
1 4 2 2156
1 2 0 94325
1 4 3 94328
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n, m, q;
// vector<int> a(n), b(n), c(n), d(n);
int a[50], b[50], c[50], d[50];

int dfs(int i, vector<int> &p) {
  int res = 0;
  if (i == n-1) {
    rep(j, q) {
      if (p[b[j]]-p[a[j]] == c[j]) res += d[j];
    }
    return res;
  }
  for (p[i+1] = p[i]; p[i+1] <= m; ++p[i+1]) {
    res = max(res, dfs(i+1, p));
  }
  return res;
}

int main() {
  cin >> n >> m >> q;
  rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  rep(i, q) --a[i], --b[i];

  vector<int> p(n);
  p[0] = 1;
  cout << dfs(0, p) << endl;
  return 0;
}