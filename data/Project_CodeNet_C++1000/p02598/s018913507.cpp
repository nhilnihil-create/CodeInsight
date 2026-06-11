#include <bits/stdc++.h>

#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;
using ll = long long;

ll N, K;
vector<ll> v;
void input() {
  cin >> N >> K;
  v.resize(N);
  for (auto &e : v) { cin >> e; }
}

// 2分探索 :binary search :BS
void solve() {
  ll l = 0;    // left   :NG
  ll r = 1e9;  // right  :OK

  while (r - l > 1) {    // 境界幅が1になったら終了
    ll x = (l + r) / 2;  // center :L/2

    // OKNGを判定するf(x)関数を作成
    // K回以内に全てx以下の長さに切れるか
    auto f = [&](ll x) {
      ll now = 0;
      rep(i, 0, N) now += (v[i] - 1) / x;
      return now <= K;
    };

    // 結果を更新し求める境界に寄せる
    if (f(x))
      r = x;
    else
      l = x;
  }
  //探索したrが答え
  cout << r << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}