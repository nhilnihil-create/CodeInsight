#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;

int main() {
    int64_t N,S;
    cin >> N >> S;
    vector<int64_t> A(N);
    for ( int64_t i = 0; i < N; ++i){
        cin >> A[i];
    }
    
    vector<vector<int64_t>> dp(N+1,vector<int64_t>(S+1,0));
    dp[0][0] = 1;
    for ( int64_t i = 1; i <= N; ++i){
        for ( int64_t j = 0; j <= S; ++j){
            if ( j - A[i-1] >= 0 ) {
                dp[i][j] = ( dp[i-1][j] * 2 + dp[i-1][j-A[i-1]] ) % MOD;
            } else {
                dp[i][j] = dp[i-1][j] * 2 % MOD;
            }
        }
    }
    
    if ( dp[N][S] < 0 ) dp[N][S] += MOD;
    cout << dp[N][S] << endl;
    
    
    return 0;
}
