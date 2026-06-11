#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 100000;
const LL MOD = (LL)1e9+7;

int N, K;
LL dp[MAXN+5], ans;

LL power(LL a,LL b){
    return b ? power(a*a%MOD,b/2)*(b%2?a:1)%MOD : 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (LL i = K; i >= 1; --i){
        dp[i] = power(K/i, N);
        for (LL j = 2 * i; j <= K; j += i) {
            dp[i] -= dp[j];
        }
        ans=(ans+i*dp[i]%MOD)%MOD;
    }
    cout << (ans + MOD) %MOD << '\n';
    return 0;
}