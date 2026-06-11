#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define MOD (1000000007)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;
const int MAX = 510000;

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


int main() {
    COMinit();

    ll N, K;
    cin >> N >> K;

    ll ret = 0;
    for(ll i = K; i <= N+1; i++) {

        ll minv = ((i % MOD) * ((i-1) % MOD) / 2) % MOD;
        ll maxv = ((i % MOD) * (((2* N-i)%MOD)+1)/2) % MOD;
        //cout << maxv << "," << minv << ":" << maxv-minv<<endl;
        ret = ret % MOD + (maxv-minv + MOD + 1) % MOD;
        ret %= MOD;
    }

    cout << ret << endl;
    return 0;
}