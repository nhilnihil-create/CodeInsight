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

ll X, Y;
Combination_Mod c(2000010, MOD);

signed main(){
    cin >> X >> Y;
    ll ans = 0;
    REP(i, X + 1){
        if((X - i) % 2 != 0) continue;
        ll j = (X - i) / 2;
        if(j != Y - 2 * i) continue;
        ans = (ans + c.bin(i + j, i)) % MOD;
    }
    PRINT(ans);
    return 0;
}