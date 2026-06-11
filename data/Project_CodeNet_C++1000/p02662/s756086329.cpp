#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 998244353;

long long pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    vector<vector<ll>> dp(n+1, vector<ll>(s+1, 0));
    dp[0][0] = pow(2ll, (ll)n);
    ll inv_2 = pow(2ll, MOD-2);
    rep(i, n) rep(j, s+1) {
        dp[i+1][j] = dp[i][j];
        if (j >= A[i]) dp[i+1][j] += dp[i][j-A[i]] * inv_2 % MOD;
        dp[i+1][j] %= MOD;
    }
    cout << dp[n][s] << endl;
    return 0;
}