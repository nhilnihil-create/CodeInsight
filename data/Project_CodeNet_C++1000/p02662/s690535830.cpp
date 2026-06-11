#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
using ll = long long;

void solve(long long N, long long S, std::vector<long long> A){
    vector<vector<ll>> dp(N + 1, vector<ll>(S + 1));
    dp[0][0] = 1;
    for(int i = 0;i < N;i++){
        for(int j = 0;j <= S;j++){
            dp[i][j] %= MOD;
            dp[i+1][j] += dp[i][j] * 2;
            if(A[i] + j <= S){
                dp[i+1][A[i] + j] += dp[i][j];
            }
        }
    }
    cout<<dp[N][S]%MOD<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long S;
    scanf("%lld",&S);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, S, std::move(A));
    return 0;
}
