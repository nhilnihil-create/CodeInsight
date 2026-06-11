#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 左端からgreedyに、累積をためておいて2*D右に来たら元に戻す
  ll N, D, A;
  cin >> N >> D >> A;
  vector<P> XH;
  rep(i, N) {
    int X, H;
    cin >> X >> H;
    XH.emplace_back(X, H);
  }
  sort(XH.begin(), XH.end());
  ll cumAttack = 0;
  ll ans = 0;
  queue<P> que;
  rep(i, N) {
    // 最初に過ぎ去った攻撃分を引く
    while (!que.empty()) {
      if (XH[i].first <= que.front().first) break;
      cumAttack -= que.front().second;
      que.pop();
    }
    int hp = XH[i].second - cumAttack;
    if (hp > 0) {
      ll time = (hp + A - 1) / A;
      ans += time;
      cumAttack += A * time;
      que.push(make_pair(XH[i].first + 2 * D, A * time));
    }
  }
  cout << ans << '\n';
  return 0;
}