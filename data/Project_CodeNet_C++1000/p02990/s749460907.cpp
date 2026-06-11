#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 1e9 + 7, N = 500005;
LL fac[N], finv[N], inv[N];

LL nCr(LL n,LL k){
    if(n < k || n < 0|| k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < N; i++){
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }    

    LL n, k, ans; cin >> n >> k;

    for(LL i = 1; i <= k; i++) {
        ans =  nCr(n - k + 1, i);
        ans *= nCr(k - 1, i - 1);
        ans %= mod;
        cout << ans << '\n';
    }   
}