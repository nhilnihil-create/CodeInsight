#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[200010][4];  // dp[i][j]
                    // i 文字目まで分割が決まって、最後が j+1 文字
                    // 分割最大数

int main() {
  string s;
  cin >> s;
  int n = s.size();

  // DPテーブル初期化
  for (int i = 0; i < 200010; i++) {
    for (int j = 0; j < 4; j++) {
      dp[i][j] = 0;
    }
  }

  // 初期値
  dp[0][0] = 1;  // 1 文字だけなら分割数は 1

  // DP遷移
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      if (i - j < 0) continue;
      for (int k = 0; k < 4; k++) {
        // dp[i+k+1][k] を決定していく
        if (i + k + 1 > n) continue;
        string bef = s.substr(i - j, j + 1);
        string aft = s.substr(i + 1, k + 1);
        if (bef == aft) {
          // 文字列が一致するときは分割せずにそのまま伸ばしたものを考える
          dp[i + k + 1][k] = max(dp[i + k + 1][k], dp[i][j]);
        } else {
          dp[i + k + 1][k] = max(dp[i + k + 1][k], dp[i][j] + 1);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 4; i++) {
    ans = max(ans, dp[n - 1][i]);
  }
  cout << ans << endl;
}
