#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, A, B, ans=0, tmp=0;
vector<ll> DP(MAXN, 0);

const ll MAX = 500000;
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
    ll res=1;
    for(int i=n-k+1;i<=n;i++) {
        res *= i;
        res %= MOD;
    }
    res *= finv[k];
    res %= MOD;
    return res;
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

signed main(){
    cin >> N >> A >> B;
    COMinit();
    //cout << COM(N, A) << " " << COM(N, B) << endl;
    ans = modpow(2, N, MOD)-1-COM(N, A)-COM(N, B);
    while(ans>=MOD||ans<0) {
        if(ans>=MOD) ans -= MOD;
        else ans += MOD;
    }
    cout << ans << endl;
    return 0;
}