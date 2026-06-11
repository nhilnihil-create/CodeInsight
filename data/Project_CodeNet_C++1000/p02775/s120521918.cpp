#include<bits/stdc++.h>
using namespace std;

vector<int> N;
int dp[1000000+1][2];

int dfs(int i, bool just) {
  if(i == N.size()) return just ? 0 : 1;
  if(dp[i][just] != -1) return dp[i][just];
  int res = 10;
  if(just) {
    res = min(N[i] + dfs(i + 1, true), N[i] + 1 + dfs(i + 1, false));
  } else {
    res = min(10 - N[i] + dfs(i + 1, true), 10 - N[i] - 1 + dfs(i + 1, false));
  }
  return dp[i][just] = res;
}

int main() {
  string S;
  cin >> S;
  for(auto c: S) N.emplace_back(c - '0');
  for(auto i=0; i<N.size(); ++i) dp[i][true] = dp[i][false] = -1;
  cout << min(dfs(0, true), 1 + dfs(0, false)) << endl;
}
