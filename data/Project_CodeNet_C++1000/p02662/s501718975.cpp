//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


const int MOD = 998244353;


long long modpow(long long x, long long n, long long mod) {
    if (n == 0) return 1;
    long long res = modpow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res; 
}


void solve() {
    int N, S; cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<long long>> dp(N, vector<long long>(S+1));

    dp[0][0] = 1;
    if (A[0] <= S) dp[0][A[0]] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j - A[i] == 0) {
                dp[i][j] += modpow(2, i, MOD);
                dp[i][j] %= MOD;
            }
            if (j - A[i] > 0) {
                dp[i][j] += dp[i-1][j-A[i]];
                dp[i][j] %= MOD;
            }
            dp[i][j] += dp[i-1][j] * 2;
            dp[i][j] %= MOD;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < S+1; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[N-1][S] << endl;
}


int main() {
    solve();
    return 0;
}
