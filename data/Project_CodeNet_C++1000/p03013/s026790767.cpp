#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;

  vector<bool> v(N+1, true);
  rep(i,0,M-1) {
    int a;
    cin >> a;
    v[a] = false;
  }

  int mod = 1'000'000'007;
  vector<ll> dp(N+1); dp[0] = 1;
  rep(i,0,N-1) {
    rep(j,i+1,min(N,i+2)) {
      if (v[j]) {
        dp[j] += dp[i];
        dp[j] %= mod;
      }
    }
  }

  cout << dp[N] << endl;
  return 0;
}
