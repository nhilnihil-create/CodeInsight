#include <bits/stdc++.h>

using namespace std;

static const long long MOD = 1e9 + 7;

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

static long long calc_comb_mod (
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
    int X, Y;
    cin >> X >> Y;

    long long ans = 0;
    /* (i+2, j+1)にa回、(i+1,j+2)にb回移動する */
    int a, b;
    for ( a = 0; 2 * a <= X; a++ ) {
        b = X - 2 * a;
        if ( a + 2 * b == Y ) {
            ans += calc_comb_mod(a+b, a);
        }
    }

    cout << ans << endl;
    return 0;
}
