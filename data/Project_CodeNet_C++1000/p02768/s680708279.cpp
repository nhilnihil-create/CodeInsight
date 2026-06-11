#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll mod_pow(ll a, ll n)
{
    ll res = 1, base = a;

    while (n)
    {
        if (n & 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;
        n >>= 1;
    }

    return res;
}

ll mod(ll a)
{
    return (((a % MOD) + MOD) % MOD);
}

ll binom(ll n, ll m)
{
    ll a = min(m, n - m);
    ll b = max(m, n - m);

    ll num = 1;

    for (ll i = n; i > b; --i)
        num = mod(num * i);

    ll den = 1;

    for (ll i = 2; i <= a; ++i)
        den = mod(den * i);

    auto inv = mod_pow(den, MOD - 2);

#ifdef DEBUG
cout << "a = " << a << ", b = " << b << endl;
cout << "num = " << num << ", den = " << den << endl;
cout << "inv = " << inv << endl;
#endif
    return mod(num * inv);
}

ll solve(ll N, ll a, ll b)
{
    ll ans = mod_pow(2, N);

#ifdef DEBUG
cout << "ans = " << ans << endl;
cout << "binom(" << N << ", " << a << ") = " << binom(N, a) << endl;
cout << "binom(" << N << ", " << b << ") = " << binom(N, b) << endl;
#endif
    ans = mod(ans - binom(N, a));
    ans = mod(ans - binom(N, b));
    ans = mod(ans - 1);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, a, b;
    cin >> N >> a >> b;

    auto ans = solve(N, a, b);

    cout << ans << '\n';

    return 0;
}
