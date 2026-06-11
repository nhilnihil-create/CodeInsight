#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < n; i++)

const ll mod = 1000000007;

int main() {
    int n,m;
    cin >> n >> m;
    int s[n];
    rep(i,n) cin >> s[i];
    int t[m];
    rep(i,m) cin >> t[i];

    ll dp[n+1][m+1];
    rep(i,n+1) rep(j,m+1) dp[i][j] = 0;

    rep(i,n) {
      rep(j,m) {
        dp[i+1][j+1] = (mod+dp[i+1][j]+dp[i][j+1]-dp[i][j])%mod;
        if (s[i] == t[j]) {
          dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] + 1)%mod;
        }
      }
    }
    cout << (dp[n][m]+1)%mod << endl;
    return 0;
}


