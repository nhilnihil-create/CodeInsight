#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

Int MOD = 1e9+7;

//---------- べき乗 ----------
Int power(Int a, Int n){
    if(a == 0) return 0;
    if(n == 0) return 1;
    
    Int res = 1;
    while(n > 0){
        if(n % 2 == 1) res = res * a % MOD;
        a = a * a % MOD; n /= 2;
    }
    return res;
}

//---------- 逆元 ----------
Int inv(Int a){
    return power(a, MOD-2);
}

int main(){
    int N, M; cin >> N >> M;
    vector<int> S(2010,0), T(2010,0);
    rep1(i,N) cin >> S[i];
    rep1(i,M) cin >> T[i];

    // dp[i][j]: S[i],T[j]までで，かつこれらをペアにする共通部分列の個数
    vector<vector<Int>> dp(2010,vector<Int>(2010,0));
    vector<vector<Int>> sum(2010,vector<Int>(2010,1));
    dp[0][0] = 1;

    rep1(i,N){
        rep1(j,M){
            if(S[i] == T[j]) dp[i][j] = (sum[i-1][j-1] + 1) % MOD;
            sum[i][j] = (sum[i-1][j] + sum[i][j-1] + MOD - sum[i-1][j-1] + dp[i][j]) % MOD;
        }
    }

    cout << (sum[N][M]-1) * inv(2) % MOD + 1 << endl;
}
