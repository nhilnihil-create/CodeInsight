#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e9;

int main() {
  // dp
  int H, N;
  cin >> H >> N;
  vector<int> dp(H+1, INF);
  dp[0] = 0;
  rep(_, N) {
    int A, B;
    cin >> A >> B;
    for (int i = 0; i < H; i++) {
      int next = min(i+A, H);
      dp[next] = min(dp[next], dp[i] + B);
    }
  }
  cout << dp[H] << '\n';
  return 0;
}