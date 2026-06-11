//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
 
using namespace std;
 
 
const int MOD = 998244353;
 

void solve() {
    int N, S; cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
 
    vector<vector<long long>> dp(N+1, vector<long long>(S+1));
 
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j - A[i-1] >= 0) {
                dp[i][j] += dp[i-1][j-A[i-1]];
                dp[i][j] %= MOD;
            }
            dp[i][j] += dp[i-1][j] * 2;
            dp[i][j] %= MOD;
        }
    }
 
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j < S+1; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
 
    cout << dp[N][S] << endl;
}
 
 
int main() {
    solve();
    return 0;
}