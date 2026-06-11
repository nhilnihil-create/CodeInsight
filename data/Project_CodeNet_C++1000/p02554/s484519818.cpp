#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

ll power(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    // cout << MOD << ' ' << n << '\n';

    ll p10 = power(10, n) % MOD;
    ll p9 = power(9, n) % MOD;
    ll p8 = power(8, n) % MOD;
    ll ans = (p10 - ((2 * p9) % MOD - p8) % MOD) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << '\n';
}