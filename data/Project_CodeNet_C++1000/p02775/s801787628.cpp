#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 1e9;
int main(){
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  s += '0';

  vector<int> dp(2,INF);
  dp[0] = 0;
  int n = sz(s);
  for (int i = 0; i < n; i++) {
    int d = s[i] - '0';
    vector<int> ndp(2,INF);
    ndp[0] = min(dp[0] + d, dp[1] + d + 1);
    ndp[1] = min(dp[0] + 10 - d, dp[1] + 9 - d);
    swap(dp, ndp);
  }
  cout << dp[0] << endl;
  return 0;
} 