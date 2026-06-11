#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 参考にしました。
// ttp://kazune-lab.net/contest/2019/08/17/agc037/#模範解答

int main() {
  string s;
  cin >> s;
  s = '#' + s;  // 1-indexed にするため。
  int len = s.size();
  int dp[200010][5];  // dp[i][j]
                      // i 文字目時点で最後の分割が S[i-j,i) であるときの分割数
                      // i, j : 1-indexed
  for (int i = 0; i < 200010; i++) {
    for (int j = 0; j < 5; j++) {
      dp[i][j] = 0;
    }
  }
  dp[1][1] = 0;  // 最後の分割は'#'なので無効
  for (int i = 1; i < len; i++) {
    for (int j = 1; j <= 4; j++) {
      // 最後の分割 S[i-j,i) を決定
      if (i - j < 0) continue;
      string bef = s.substr(i - j, j);
      for (int k = 1; k <= 4; k++) {
        // 新しい分割 S[i,i+k) を決定
        if (i + k > len) continue;
        string aft = s.substr(i, k);
        // 分割が不一致なら遷移を計算
        if (bef != aft) {
          dp[i + k][k] = max(dp[i + k][k], dp[i][j] + 1);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i < 5; i++) {
    ans = max(ans, dp[len][i]);
  }

  cout << ans << endl;
}