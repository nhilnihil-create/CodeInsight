#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

using ll = long long;
using P = pair<int, int>;

const int mod = 998244353;

int main(int, char**)
{
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector< vector<ll> > dp(n+1, vector<ll>(s+1,0));
    dp[0][0] = 1;
    rep(i,n) rep(j,s+1) {
        dp[i+1][j] += dp[i][j] << 1;
        dp[i+1][j] %= mod;
        if (j + a[i] <= s) {
            dp[i+1][j+a[i]] += dp[i][j];
            dp[i+1][j+a[i]] %= mod;
        }
    }

    cout << dp[n][s] << endl;

    return 0;
}