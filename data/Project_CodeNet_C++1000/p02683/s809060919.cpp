#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int a[12][12];
const int INF = 1e9;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  rep(i, n) {
    cin >> c[i];
    rep(j, m) { cin >> a[i][j]; }
  }

  int ans = INF;
  rep(s, 1 << n) {
    int cost = 0;
    vector<int> d(m);
    rep(i, n) {
      if(s >> i & 1) {
        cost += c[i];
        rep(j, m) d[j] += a[i][j];
      }
    }
    bool f = true;
    rep(j, m) if(d[j] < x) f = false;
    if(f)
      ans = min(ans, cost);
  }

  if(ans == INF)
    ans = -1;
  cout << ans;
}
