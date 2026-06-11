#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int A[3005];
long long pow2[3005];

long long memo[3005][3005];

long long dp(int i, int j){
    if(j == 0){
        return pow2[i];
    }else if(i == 0){
        return 0;
    }else if(memo[i][j] != -1){
        return memo[i][j];
    }else{
        long long ans = 0;

        // ignore
        if(i > 0){
            ans += 2*dp(i-1, j);
        }

        // take
        if(j >= A[i-1]){
            ans += dp(i-1, j-A[i-1]);
        }

        return memo[i][j] = ans%MOD;
    }
}

int main(){
    int N, S;
    scanf("%d%d", &N, &S);

    for(int i = 0; i < N; i ++){
        scanf("%d", &A[i]);
    }

    pow2[0] = 1;
    for(int i = 1; i <= N; i ++){
        pow2[i] = 2*pow2[i-1]%MOD;
    }

    memset(memo, -1, sizeof(memo));
    printf("%lld", dp(N, S));
    return 0;
}
