#include <iostream>
using namespace std;

//二項計数常よをサクっと求める。逆元
const int MAX = 4000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    COMinit();
    int N,K;
    cin >> N >> K;
    for(int i = 1; i <= K; i++){
        long long blue = COM(K - 1, i - 1)%MOD;
        long long red =COM(N - K + 1,i)%MOD;
        cout << blue*red%MOD << endl;
    }        
}