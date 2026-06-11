#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    u64 N, S;
    cin >> N >> S;

    vector<u64> A(N);
    for(u64 n=0; n<N; n++) cin >> A[n];
    
    vector<vector<s64>> dp(N+1, vector<s64>(S+1, 0));
    u64 mod = 998244353;
    dp[0][0] = 1;
    
    for(u64 i=0; i<N; i++) {
        for(u64 k=0; k<=S; k++) {
            dp[i+1][k] = (dp[i][k] * 2) % mod;
            if(A[i] <= k) {
                dp[i+1][k] = (dp[i+1][k] + dp[i][k-A[i]]) % mod;
            }
        }
    }

    cout << dp[N][S] << endl;
    return 0;
}