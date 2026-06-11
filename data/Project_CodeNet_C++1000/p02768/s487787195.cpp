#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

static long long calc_exp_mod (
    long long base,
    long long exponent)
{
    if ( exponent == 1 )
        return base;
    if ( exponent % 2 != 0 )
        return base * calc_exp_mod(base, exponent-1) % MOD;
    long long sqrt = calc_exp_mod(base, exponent/2);
    return (sqrt * sqrt) % MOD;
}

static long long calc_combin_mod (
    long long n,
    long long k)
{
    long long x = 1;
    long long y = 1;

    for ( int i=0; i<k; i++ ) {
        x *= n - i;
        y *= i + 1;
        x %= MOD;
        y %= MOD;
    }
    y = calc_exp_mod(y, MOD-2);
    return (x * y) % MOD;
}

int main (void) {
    long long n, a, b;
    cin >> n >> a >> b;

    long long ans = calc_exp_mod(2, n) - 1;
    ans += MOD - calc_combin_mod(n, a);
    ans %= MOD;
    ans += MOD - calc_combin_mod(n, b);
    ans %= MOD;

    cout << ans << endl;
    return 0;
}

