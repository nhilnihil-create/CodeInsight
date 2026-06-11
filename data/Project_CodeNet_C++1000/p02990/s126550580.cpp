#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long MOD = 1e9 + 7;
long long repow(long long x, long long y){
    if(y == 0) return 1;
    if(y % 2 == 0){
        long long t = repow(x, y / 2);
        return t* t % MOD;
    }
    return x * repow(x, y - 1) % MOD;
}
const int MAX = 2010;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = 1;
    finv[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = repow(i, MOD - 2);
        finv[i] = finv[i -1] * inv[i] % MOD;
    }
}
long long COM(long long n, long long k){
    if(k > n || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n - k] % MOD;
}
int main(){
    COMinit();
    int N, K;
    cin >> N >> K;
    int aka = N - K;
    for(int i = 1; i <= K; i++){
        long long ans = COM(aka + 1, i) * COM(K - 1, i - 1) % MOD;
        cout << ans << endl;
    }
}