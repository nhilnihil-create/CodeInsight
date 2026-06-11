#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e+09 + 7;

int main() {
    string S;
    cin >> S;
    int64_t N = S.size();
    
    vector<vector<int64_t>> dp(N,vector<int64_t>(13,0));
    
    if ( S.at(N-1) == '?' ){
        for ( int64_t j = 0; j < 10; ++j){
            dp[N-1][j] = 1;
        }
    } else {
        int num = S.at(N-1) - '0';
        dp[N-1][num] = 1;
    }
    
    int ten = 10;
    for ( int64_t i = N-1; i >= 1; --i){
        if ( S.at(i-1) == '?' ){
            for ( int64_t k = 0; k < 10; ++k){
                for ( int64_t j = 0; j < 13; ++j){
                    dp[i-1][( k * ten + j ) % 13] = ( dp[i-1][( k * ten + j ) % 13] + dp[i][j] ) % MOD;
                }
            }
        } else {
            int64_t num = S.at(i-1) - '0';
            for ( int64_t j = 0; j < 13; ++j){
                dp[i-1][( num * ten + j ) % 13] = ( dp[i-1][( num * ten + j ) % 13] + dp[i][j] ) % MOD;
            }
        }
        /*for ( int64_t j = 0; j < 13; ++j){
            dp[i-1][j] = dp[i-1][j] % MOD;
        }*/
        ten = ( ten * 10 ) % 13;
    }
    
    /*for ( int i = 0; i < N; ++i){
        for ( int j = 0; j < 13; ++j){
            cout << i << j << " " << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    
    cout << dp[0][5] << endl;
    
    return 0;
}
