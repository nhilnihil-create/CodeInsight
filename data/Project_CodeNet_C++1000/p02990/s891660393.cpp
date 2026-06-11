#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

Int modpow(Int a, Int n, Int mod) {
    Int ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }

    return ret;
}

vector<Int> factorials, invs;
bool is_ncr_table = false;
void calc_ncr_table(Int n, Int mod) {
    is_ncr_table = true;

    // 1! ~ n! の計算
    Int f = 1;
    factorials.push_back(f);
    for (Int i = 1; i <= n; i++) {
        f *= i;
        f %= mod;
        factorials.push_back(f);
    }

    // n!^-1 の計算
    Int inv = modpow(factorials[n], mod - 2, mod);
    // (n-1)!^-1 ~ 1!^-1 の計算
    invs.assign(n, 1);
    invs[n] = inv;
    for (Int i = n; i >= 1; i--) {
        inv *= i;
        inv %= mod;
        invs[i - 1] = inv;
    }
}

Int factorial(Int n, Int mod = 1) {
    Int ret = 1;
    if (mod == 1) {
        for (Int i = 1; i <= n; i++) {
            ret *= i;
        }

        return ret;
    } else {
        for (Int i = 1; i <= n; i++) {
            ret *= i;
            ret %= mod;
        }

        return ret;
    }
}

Int ncr(Int n, Int r, Int mod) {
    if (n < r) {
        return (Int)0;
    } else {
        if (is_ncr_table) {
            // modが素数の場合のみ
            return (factorials[n] * invs[r] % mod) * invs[n - r] % mod;
        } else {
            Int x = 1;
            for (Int i = n - r + 1; i <= n; i++) {
                x *= i;
                x %= mod;
            }
            return x * modpow(factorial(r, mod), mod - 2, mod) % mod;
        }
    }
}

int main() {
    Int n, k;
    cin >> n >> k;

    calc_ncr_table(2010, MOD);

    vector<Int> rr(k);
    for (Int i = 0; i <= k - 1; i++) {
        rr[i] = ncr(k - 1, i, MOD) % MOD;
    }

    for (Int i = 1; i <= k; i++) {
        Int ans = 0;
        Int nn = n - k + 1;
        ans += ncr(nn, i, MOD);
        ans *= rr[i - 1] % MOD;
        ans %= MOD;
        cout << ans << endl;
    }

    return 0;
}