#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

class Combination {
   public:
    Combination(int n) {
        fac = new ll[n];
        inv = new ll[n];
        finv = new ll[n];
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        REP(i, 2, n) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    ll cnr(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

   private:
    ll *fac, *inv, *finv;
};

int main() {
    int N, K; cin >> N >> K;
    Combination comb(N);

    for (int i = 1; i <= K; i++) {
        cout << (comb.cnr(N - K + 1, i) * comb.cnr(K - 1, i - 1)) % MOD << endl;
    }
    return 0;
}