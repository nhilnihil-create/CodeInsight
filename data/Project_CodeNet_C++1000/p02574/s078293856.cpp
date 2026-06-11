#include <iostream>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep2(i, n) for(ll i = 2; i <=(ll)(n); i++)
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
    ll n;
    cin >> n;
    ll a[n+1];
    ll maxa = -1;
    rep1(i, n){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    ll min_divisor[maxa+1]; //1より大きい最小の約数
    rep0(i, maxa) min_divisor[i] = 0;
    for(int i = 2; i <= maxa; i++){
        if(min_divisor[i] == 0){
            min_divisor[i] = i;
            for(ll j = 2*i; j <= maxa; j += i){
                min_divisor[j] = i;
            }
        }   
    }
    ll prime_cnt[maxa+1]; //a[]の素因数の数
    rep0(i, maxa) prime_cnt[i] = 0;
    rep1(i, n){
        set<ll> tmp;
        if(a[i] == 1) continue;
        ll dividend = a[i];
        ll divisor = min_divisor[a[i]];
        tmp.insert(divisor);
        while(divisor != dividend){
            dividend = dividend / divisor;
            divisor = min_divisor[dividend];
            tmp.insert(divisor);
        }
        for(auto x: tmp){
            prime_cnt[x]++;
            //cout << x << " ";
        }
        //cout << endl;
    }
    
    bool pairwise = true;
    bool setwise = true;
    rep2(i, maxa){
        if(prime_cnt[i] >= 2){
            pairwise = false;
            break;
        }
    }
    int gcd_all = gcd(a[1], a[2]);
    rep2(i, n-1) gcd_all = gcd(gcd_all, a[i+1]);
    if(gcd_all != 1)  setwise = false;

    if(pairwise){
        cout << "pairwise coprime" << endl;
    }else if(setwise){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }

    return 0;
}