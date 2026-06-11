#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  string S;
  cin >> S;
  set<string> s;
  int n = S.length();
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  if (n == 2) {
    if (S[0] == S[1]) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
    return 0;
  }
 
  int dp[n]{};
  // 1文字目
  dp[0] = 1;
  // 2文字目
  if (S[0] == S[1]) {
    dp[1] = 1; // aa -> a, a
  } else {
    dp[1] = 2; // ab -> a, b
  }
  // 3文字目
  if (S[0] != S[1] && S[1] != S[2]) {
      dp[2] = 3; // aba -> a, b, a
  } else {
      dp[2] = 2; // ?aa -> ?a, a
  }
  for (int i = 3; i < n; i++) {
      if (S[i - 1] == S[i]) {
          dp[i] = dp[i - 3] + 2; // ??aa -> ?, ?a, a or ?, ?, aa
      } else {
          dp[i] = dp[i - 1] + 1; // ?ab -> ?, a, b or ?a, b
      }
  }
  cout << dp[n - 1] << "\n";
  return 0;
}
