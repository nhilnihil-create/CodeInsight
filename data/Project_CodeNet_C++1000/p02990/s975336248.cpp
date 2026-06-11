#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

const ll MAX = 1e6+7;
ll fac[MAX], finv[MAX], inv[MAX];
//初期化
void COMinit() {
    fac[0]  = fac[1]  = 1;
    finv[0] = finv[1] = 1;
    inv[1]  = 1;

    for(int i = 2; i < MAX; ++i){
        fac[i]  = fac[i - 1] * i % MOD;
        inv[i]  = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
//nCk
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    ll n, k;
    cin >> n >> k;

    COMinit();

    for(ll i = 1; i <= k; ++i){
        cout << (COM(n-k+1, i) * COM(k-1, i-1)) % MOD << endl;
    }

}