#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // K回ごとのジャンケンでdp、状態は前回勝ったか負けたか、r, s, p を数字に変換
  int N, K;
  cin >> N >> K;
  vector<int> RSP(3);
  rep(i, 3) cin >> RSP[i];
  string T;
  cin >> T;
  vector<int> ctoi(256);
  ctoi['r'] = 2;
  ctoi['s'] = 0;
  ctoi['p'] = 1;
  int ans = 0;
  rep(i, K) {
    vector<int> X;
    for (int j = i; j < N; j = j + K) {
      X.push_back(ctoi[T[j]]); // 勝つ出し方をXに入れる
    }
    int last = -1;
    vector<int> dp(2);
    for (int x : X) {
      vector<int> prev(2);
      swap(dp, prev);
      dp[0] = max(prev[0], prev[1]);  // 負けた状態
      if (x == last) {
        dp[1] = prev[0] + RSP[x];
      } else {
        dp[1] = max(prev[0], prev[1]) + RSP[x];
      }
      last = x;
    }
    ans += max(dp[0], dp[1]);
  }
  cout << ans << '\n';  
  return 0;
}