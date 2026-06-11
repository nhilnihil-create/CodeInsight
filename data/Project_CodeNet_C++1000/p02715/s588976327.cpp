#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long mod_pow(long long x, long long y){
    if(y == 0) return 1;
    long long res = 1;
    while(y != 0){
        if(y & 1) res = res*x%MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}
int main(){
    long long N, K;
    cin >> N >> K;
    long long ans = 0;
    vector<long long> cnt(K + 1, 0);
    for(long long i = K; i >= 1; i--){
        long long cnttemp = mod_pow(K / i, N);
        long long t = i + i;
        while(t <= K){
            cnttemp = (cnttemp - cnt[t] + MOD) % MOD;
            t += i;
        }
        ans = (ans + cnttemp * i % MOD) % MOD;
        cnt[i] = cnttemp;
    }
    cout << ans << endl;
}
