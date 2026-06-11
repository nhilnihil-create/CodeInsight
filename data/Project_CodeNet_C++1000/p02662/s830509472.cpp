#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 998244353LL;

ll dp[3300][3300];

int main() {
  ll n, s;
  cin >> n >> s;
  vll a(n);
  rep(i,n) cin >> a[i];
  dp[0][0] = 1;
  for(int i = 1; i<=n; i++) {
    for(int j = 0; j<=s; j++) {
      dp[i][j] = dp[i-1][j]*2;
      if(j-a[i-1]>=0) dp[i][j] += dp[i-1][j-a[i-1]];
      dp[i][j] %= mod;
    }
  }
  cout << dp[n][s] << endl;
  return 0;
}
