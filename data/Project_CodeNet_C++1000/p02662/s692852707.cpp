// 解き直し.
// https://img.atcoder.jp/abc169/editorial.pdf
// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const LL MOD = 998244353;
LL dp[3030][3030], a[3030], memo[3030], mPow2[3030];

int main(){
    
    // 1. 入力情報.
    int N, S;
    scanf("%d %d", &N, &S);
    rep(i, N) scanf("%lld", &a[i]);
    
    // 2. 2 の べき乗 を 保存.
    mPow2[0] = 1;
    repx(i, 1, 3030) mPow2[i] = mPow2[i - 1] * 2, mPow2[i] %= MOD;
    
    // 3. dp更新.
    repx(i, 1, N + 1){
        repr(j, S, 0){
            int d = j - (int)a[i - 1];
            if(d > 0 && memo[d]) dp[i][j] += dp[i - 1][d], dp[i][j] %= MOD, memo[j]++;
            if(d == 0)           dp[i][j] += mPow2[i - 1], memo[j]++;
            dp[i][j] += dp[i - 1][j] * 2;
            dp[i][j] %= MOD;
        }
    }
    
    // 4. 出力.
    printf("%lld\n", dp[N][S]);
    return 0;
    
}