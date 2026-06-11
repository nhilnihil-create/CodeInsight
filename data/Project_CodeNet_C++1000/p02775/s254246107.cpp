#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  vector<int> n;
  for (char c: s) {
    n.push_back(c - '0');
  }
  int len = n.size();
  reverse(n.begin(), n.end());
  long long dp[len][2];
  for (int i=0; i<len; i++) {
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  dp[0][0] = n[0];
  if (n[0] > 0) {
    dp[0][1] = 10 - n[0];
  }
  for (int i=1; i<len; i++) {
    dp[i][0] = dp[i-1][0] + n[i];
    if (n[i] > 0) {
      dp[i][1] = dp[i-1][0] + 10 - n[i];
    } else {
      dp[i][1] = -1;
    }
    if (dp[i-1][1] > -1) {
      if (n[i] < 9) {
        dp[i][0] = min(dp[i-1][1] + n[i] + 1, dp[i][0]);
      }
      if (n[i] > 0) {
        dp[i][1] = min(dp[i-1][1] + 9 - n[i], dp[i][1]);
      } else {
        dp[i][1] = dp[i-1][1] + 9 - n[i];
      }
    }
  }
  long long ans = dp[len-1][0];
  if (dp[len-1][1] > -1) {
    ans = min(dp[len-1][1] + 1, ans);
  }
  cout<<ans<<endl;
}