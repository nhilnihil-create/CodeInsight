#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;


int dp[20010];

int main() {
  int h, n;
  cin >> h >> n;
  rep(i,20011) dp[i] = INF;
  dp[0] = 0;
  vector<P> a(n);
  rep(i,n) cin >> a[i].first >> a[i].second;
  for(int i = 1; i <= 20010; i++) {
    rep(j,n) {
      if(i>=a[j].first) dp[i] = min(dp[i],dp[i-a[j].first]+a[j].second);
    }
  }
  int ans = INF;
  for(int i = h; i<= 20010; i++) ans = min(ans,dp[i]);
  cout << ans << endl;
  return 0;
}