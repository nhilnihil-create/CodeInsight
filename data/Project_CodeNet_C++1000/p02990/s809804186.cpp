#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, K, ans=0, tmp=0;
vector<ll> A(MAXN, 0);

const int MAX = 510000;
const int MOD = 1000000007;

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
signed main(){
    cin >> N >> K;
    COMinit();
    for(int i=1;i<=K;i++) {
        if(i>N-K+1) {
            cout << 0 << endl;
        }
        else {
            ans = COM(N-K+1, i)*COM(K-1, i-1);
            ans %= MOD;
            cout << ans << endl;
        }
    }
    return 0;
}