#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    rep(i, n)cin >> s[i];
    rep(i, m)cin >> t[i];
    ll mod = 1000000007;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 1));
    rep(i, n)rep(j, m){
        if(s[i] == t[j]){
            dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1]) % mod;
        }else{
            dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1] - dp[i][j] + mod) % mod;
        }
    }
    cout << dp[n][m] << endl;
}