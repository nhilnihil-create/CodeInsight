#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow(ll a, ll b, ll c)
{

    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res %= c;
        }

        a *= a;
        a %= c;
        b >>= 1;
    }
    return res;
}

main()
{
    ll n, k;
    cin >> n >> k;
    ll mod = 1000000007;

    ll d_dash[k + 1];

    for (int i = 1; i <= k; i++)
    {
        d_dash[i] = pow(floorl(k / i), n, mod);
    }

    ll d[k + 1];

    for (int i = k; i >= 1; i--)
    {
        ll sum = 0;
        ll ul = floor(k / i);
        for (int j = 2; j <= ul; j++)
        {
            sum += d[j * i];
        }
        d[i] = d_dash[i] - sum;
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += i * d[i];
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}