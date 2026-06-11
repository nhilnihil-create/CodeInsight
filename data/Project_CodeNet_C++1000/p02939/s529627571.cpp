#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  vector<int> dp(s.size());
  dp[0] = 1;
  if (2 <= s.size()) dp[1] = (s[0] == s[1] ? 1 : 2);
  if (3 <= s.size()) dp[2] = (s[0] != s[1] && s[1] != s[2] ? 3 : 2);

  for (int i = 3; i < s.size(); i++) {
    if (s[i - 1] != s[i]) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = dp[i - 3] + 2;
    }
  }

  cout << dp[s.size() - 1] << endl;
  return 0;
}
