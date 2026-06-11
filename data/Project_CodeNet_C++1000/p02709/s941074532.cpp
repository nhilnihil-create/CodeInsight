#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

const ll INF = 1e18;
const int MX = 2005;
ll dp[MX][MX];

inline void chmax(ll& a, ll b) {
  a = max(a, b);
}
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n+1; i++) {
    for(int j = 0; j < n+1; j++) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;
  vector<pair<int, int> > p;
  for(int i = 0; i < n; i++) {
    p.emplace_back(make_pair(a[i], i));
  }
  sort(p.rbegin(), p.rend());
  for(int i = 0; i < n; i++) {
    int pi = p[i].second;
    for(int l = 0; l < i+1; l++) {
      int r = i-l;
      chmax(dp[i+1][l+1], dp[i][l]+ll(pi-l)*a[pi]);
      chmax(dp[i+1][l], dp[i][l]+ll((n-r-1)-pi)*a[pi]);
    }
  }
  ll ans = 0;
  for(int i = 0; i < n+1; i++) { 
    chmax(ans, dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}