#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int W,N;
  cin >> W >> N;
  vector<ll> dp(W+1,100000000000);
  dp[0] = 0;
  int w,v;
  rep(i,N) {
    cin >> w >> v;
    rep(j,W+1) dp[j] = min(dp[j], dp[max(0,j-w)]+v);
  }
  cout << dp[W] << endl;
  return 0;
}