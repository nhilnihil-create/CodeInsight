#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

ll prime_factrization(const ll n)
{
    ll ans = 1;
    ll p = n;
    for (ll i = 2; i <= sqrt(n); ++i)
    {
        ll c = 0;
        while (p % i == 0)
        {
            p /= i;
            ++c;
        }
        if (c != 0)
        {
            ans *= c + 1;
        }
    }

    if (p > sqrt(n))
        ans *= 2;

    return ans - 1;
}

int main()
{
    ll n;
    cin >> n;

    ll ans = prime_factrization(n - 1);
    for (ll i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            ll t = n;
            while (t % i == 0)
                t /= i;
            if ((t % i) == 1)
                ++ans;
        }
    }

    cout << ans + 1 << endl;
}