#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAX = 1000000;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

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
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    COMinit();
    ll X, Y, ans = 0;
    cin >> X >> Y;
    ll x1, x2;
    if(2*X-Y >= 0 && (2*X-Y)%3 == 0){
        x2 = (2*X-Y)/3;
        if(X-2*x2 >= 0){
            x1 = X-2*x2;
            ans = COM(x1+x2, x1);
        }
    }
    cout << ans << endl;
    return 0;
}