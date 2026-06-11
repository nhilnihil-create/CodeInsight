#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int INF = 1000000007;

int main(){
  int n, m; cin >> n >> m;
  vector<pair<int, int>> key;
  rep(i, m){
    int a, b; cin >> a >> b;
    int x = 0;
    rep(j, b){
      int c; cin >> c;
      c--;
      x |= 1 << c;
    }
    key.emplace_back(x, a);
  }

  vector<int> dp(1<<n, INF);
  dp[0] = 0;
  rep(i, 1<<n){
    rep(j, m){
      int t = i | key[j].first;
      int cost = dp[i] + key[j].second;
      dp[t] = min(dp[t], cost);
    }
  }
  int ans = dp.back();
  if(ans == INF){
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
