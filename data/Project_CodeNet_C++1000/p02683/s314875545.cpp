#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)n; i++)
const int INF = 1001001001;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  std::vector<std::vector<int>> a(n,std::vector<int>(m));
  std::vector<int> c(n);
  rep(i,n) {
    cin >> c.at(i);
    rep(j,m) cin >> a.at(i).at(j);
  }

  int ans = INF;
  // 000,001,,,111などn桁分bitで表す
  rep(s,1<<n) {
    int cost = 0;
    std::vector<int> d(m);
    // 001などで一桁ずつ調べる
    // 1となっているのが本を購入する場合
    rep(i,n) {
      if ((s>>i)&1) {
        cost += c.at(i);
        // 購入した結果得られるアルゴリズム理解度
        rep(j,m) d.at(j) += a.at(i).at(j);
      }
    }
    bool ok = true;
    // 理解度が足りていないものが一つでもあればfalse
    rep(j,m) if (d.at(j) < x) ok = false;
    if (ok) ans = min(ans, cost);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
