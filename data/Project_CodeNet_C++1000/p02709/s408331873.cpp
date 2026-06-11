#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  for(int i = 0; i < n; i++) {
    int joy;
    cin >> joy;
    p.push_back(make_pair(joy, i));
  }
  sort(p.rbegin(), p.rend());

  ll dp[n+1][n+1];
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j] = 0;
    }
  }
 
  for(int i = 0; i < n; i++) {
    int joy = p[i].first;
    int index = p[i].second;
    for(int l = 0; l < i+1; ++l) {
      int r = i-l;
      ll moved_joy = ll(abs(index-(n-r-1)))*joy;
      dp[i+1][l] = max(dp[i+1][l], dp[i][l]+moved_joy);
      moved_joy = ll(abs(index-l))*joy;
      dp[i+1][l+1] = max(dp[i+1][l+1], dp[i][l]+moved_joy);
    }
  }

  ll ans = 0;
  for(int i = 0; i < n+1; ++i) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}