#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;

ll binary_pow(ll n, ll p)
{
    return p ? binary_pow(n * n % MOD, p >> 1) * (p & 1 ? n : 1) % MOD : 1;
}

ll factorial(ll n)
{
    ll ret = 1;
    for (int i = 1; i <= n; i++)
        ret = ret * i % MOD;
    return ret;
}

int main()
{
    int x, y;
    cin >> x >> y;

    int sum = (x + y) / 3;
    if ((x + y) % 3 || x - sum < 0 || y - sum < 0)
    {
        cout << 0 << endl;
        return 0;
    }

    x -= sum;
    y -= sum;
    ll ans = factorial(x + y) % MOD;
    ans = ans * binary_pow(factorial(x), MOD - 2) % MOD;
    ans = ans * binary_pow(factorial(y), MOD - 2) % MOD;

    cout << ans % MOD << endl;
    return 0;
}