#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n,m;
  cin >> n >> m;
  int inf = 1000000000;
  vector<vector<int>> dp(m+1, vector<int>((1<<n)+1, inf));
  dp[0][0] = 0;
  rep(i,0,m) {
    int a,b;
    cin >> a >> b;
    int mask = 0;
    rep(j,0,b) {
      int c;
      cin >> c;
      mask |= 1<<(c-1);
    }
    rep(j,0,1<<n) {
      if (dp[i][j] == inf) continue;
      chmin(dp[i+1][j], dp[i][j]);
      chmin(dp[i+1][j|mask], dp[i][j]+a);
    }
  }
  if (dp[m-1][(1<<n)-1] == inf) cout << -1 << endl;
  else cout << dp[m-1][(1<<n)-1] << endl;
  return 0;
}
