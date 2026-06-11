#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)

int N, M;
string S;
vector<bool> dp;
vector<int> ans;
bool dfs(int n) {
  if (n == 0)
    return true;
  if (!dp[n])
    return false;

  rrep(i, M) {
    if (n-i < 0)
      continue;
    if (i == 0)
      continue;
    if (S[n-i] == '0') {
      ans.push_back(i);
      bool s = dfs(n-i);
      if (s == false) {
        ans.pop_back();
        continue;
      } else {
        return true;
      }
    }
  }
  return dp[n] = false;
}

int main() {
  cin >> N >> M;
  cin >> S;
  dp.resize(N+1, true);
  if (!dfs(N))
    cout << "-1";
  else {
    reverse(ans.begin(), ans.end());
    for (const auto& e : ans)
      cout << e << " ";
  }
  cout << "\n";

  return 0;
}
