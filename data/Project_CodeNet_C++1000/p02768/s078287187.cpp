#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

const Int MOD = 1000000007;
const Int MAX = 200010;


Int fac[MAX], finv[MAX], inv[MAX], fac2[MAX];

void COMinit(Int n) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    fac2[0] = n;
    fac2[1] = n * (n-1) % MOD;
    for (int i=2; i<MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        fac2[i] = fac2[i-1] * (n-i) % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

/*Int COM(Int n, Int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}*/

Int COM2(Int n, Int k) {
    if (n < k) return 0;
    if (k < 0) return 0;
    return fac2[k-1] * finv[k] % MOD;
}


Int modpow(Int a, Int m) {
    Int res = 1;
    while (m > 0) {
        if (m & 1) res = res * a % MOD;
        a = a * a % MOD;
        m >>= 1;
    }
    return res;
}

int main(){ 


    Int n, a, b, ans;
    cin >> n >> a >> b;

    COMinit(n);

    ans = modpow(2,n);

    ans = (ans + (MOD - COM2(n, a))) % MOD;
    ans = (ans + (MOD - COM2(n, b))) % MOD;
    ans = (ans + (MOD - 1)) % MOD;

    cout << ans << endl;
}
