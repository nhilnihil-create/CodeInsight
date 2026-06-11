#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

class Combination_Mod{
    public:
        Combination_Mod(long long MAX, long long MOD) : fact(MAX + 1), inv(MAX + 1), finv(MAX + 1), MAX(MAX + 1), MOD(MOD){
            init();
        }

        void init(){
            fact[0] = fact[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;
            for(long long i = 2; i < MAX; ++i){
                fact[i] = fact[i - 1] * i % MOD;
                inv[i] = MOD - inv[MOD % i] *  (MOD / i) % MOD;
                finv[i] = finv[i - 1] * inv[i] % MOD;
            }
        }

        long long bin(long long n, long long r){
            if(n < r || n < 0 || r < 0) return 0;
            return fact[n] * (finv[r] * finv[n - r] % MOD) % MOD;
        }

        long long perm(long long n, long long r){
            return (bin(n, r) * fact[r]) % MOD;
        }

        long long factorial(long long n){
            return fact[n];
        }

        long long modinv(long long n){
            return inv[n];
        }

        long long modfinv(long long n){
            return finv[n];
        }

    private:
        vector<long long> fact;
        vector<long long> inv;
        vector<long long> finv;
        const long long MAX;
        const long long MOD;
};

ll modpow(ll x, ll n){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n = (n >> 1);
    }
    return ret;
}

ll inv[200010], finv[200010];

// return nCr
long long combination(long long n, long long r){
    r = (r < n - r) ? r : n - r;
    long long c = 1;
    for(long long k = 1; k <= r; ++k){
        c = (c * n) % MOD * inv[k];
        c %= MOD;
        n--;
    }
    return c;
}

Combination_Mod c(200010, MOD);

signed main(){
    ll n, a, b;
    cin >> n >> a >> b;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR(i, 2, 200010){
        inv[i] = MOD - inv[MOD % i] *  (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
    PRINT((modpow(2, n) + MOD - combination(n, a) + MOD - combination(n, b) + MOD - 1) % MOD);
    return 0;
}