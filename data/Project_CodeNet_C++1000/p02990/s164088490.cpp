#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int mod = 1000000007;
int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(2001,vector<int>(2001,1));
    rep(i,2000){
        rep(j,2000){
            dp[i+1][j+1] = (dp[i][j+1] + dp[i+1][j]) % mod;
        }
    }
    rep(i,k){
        int a = i+1;
        ll ans = 1;
        if (n-k+1 < a){
            cout << 0 << endl;
            continue;
        }
        ans *= dp[a][n-k+1-a];
        ans *= dp[i][k-1-i];
        ans %= mod;
        cout << ans << endl;
    }
}