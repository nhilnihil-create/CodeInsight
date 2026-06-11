#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define erep(i, n) for (ll i = 1; i <= (n); i++)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }
  int ans = 1e9;
  for (int bit = 0; bit < (1 << n); bit++) {
    int monny = 0;
    vector<int> rikaido(m);
    rep(i, n) {
      if (bit & (1 << i)) {
        monny += c[i];
        rep(j, m) rikaido[j] += a[i][j];
      }
    }
    bool yoshi = true;
    rep(i, m) if (rikaido[i] < x) yoshi = false;
    if (yoshi) mins(ans, monny);
  }
  if (ans != 1e9)
    cout << ans << '\n';
  else
    cout << -1 << '\n';
  return 0;
}