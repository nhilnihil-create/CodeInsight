#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)

ll pow(ll a, ll n) { //compute a^n with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll pow(ll a, ll n, ll mod) { //compute a^n (mod mod) with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 199;
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
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//順列計算
ll PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}

int main(){
    ll n, m;
    ll max = 1e5;
    int mod = 1e9 + 7;
    bool isbroken[max+1];
    ll cnt[max+1];
    rep0(i,max) isbroken[i] = false;
    rep0(i,max) cnt[i] = 0;
    cin >> n >> m;
    rep1(i,m){
        ll tmp;
        cin >> tmp;
        isbroken[tmp] = true;
    }

    cnt[0] = 1;
    if(!isbroken[1]) cnt[1] = 1;
    for(int i = 2; i <= n;i++){
        if(!isbroken[i]){
            if(isbroken[i-1] && isbroken[i-2]){
                continue;
            }else if(isbroken[i-1]){
                cnt[i] = cnt[i-2] % mod;
            }else if(isbroken[i-2]){
                cnt[i] = cnt[i-1] % mod;
            }else{
                cnt[i] = (cnt[i-1] + cnt[i-2]) % mod;
            }
        }
    }
    cout << cnt[n] << endl;

    return 0;
}