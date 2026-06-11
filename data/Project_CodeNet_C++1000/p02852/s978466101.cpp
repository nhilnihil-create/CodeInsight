#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  string S;
  cin >> N >> M >> S;

  // dp[i] := i番目のマスからN番目のマスまで行くときに振るサイコロの回数の最小値
  vector<int> dp(N + 1, 0);
  // r := (r <= i+M and dp[r] != -1) をみたす最大の r
  int r = N;
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == '1') {
      dp[i] = -1;
      continue;
    }
    while (r > i + M) {
      r--;
    }
    while (dp[r] == -1) {
      r--;
    }
    if (i == r) {
      cout << -1 << endl;
      return 0;
    }
    dp[i] = dp[r] + 1;
  }

  vector<int> ans;
  int now = 0;
  for (int i = 0; i <= N; i++) {
    if (dp[i] == -1) {
      continue;
    }
    if (dp[i] != dp[now]) {
      ans.push_back(i - now);
      now = i;
    }
  }
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i];
    cout << (i == (int)ans.size() - 1 ? "\n" : " ");
  }

  return 0;
}