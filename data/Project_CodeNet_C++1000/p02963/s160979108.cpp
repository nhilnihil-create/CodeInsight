#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll MAX = 1000000000l;
void solver(ll s, ll *x, ll *y)
{

    x[0] = 0, y[0] = 0;
    if (s <= MAX)
    {
        x[1] = 1, y[2] = s;
        x[2] = 0, y[1] = 0;
    }
    else if ((ll)(sqrt(s)) * (ll)(sqrt(s)) != s)
    {
        ll t = (ll)(sqrt(s));
        ll r = (ll)(sqrt(s));
        while (t * r >= s)
        {
            --t, --r;
        }
        rep(p, t, MAX + 1)
        {
            rep(q, r, MAX + 1)
            {
                if (p * q < s)
                    continue;
                ll a = p * q - s;
                x[1] = p, y[2] = q;

                rep(i, 1, (ll)(sqrt(a)) + 1)
                {
                    if (a % i == 0 && a / i <= MAX && i <= MAX)
                    {
                        x[2] = i, y[1] = a / i;
                        return;
                    }
                }
            }
        }
    }
    else
    {
        x[1] = sqrt(s), y[2] = sqrt(s);
        x[2] = 0, y[1] = 0;
    }
}
int main()
{
    ll s;
    cin >> s;
    ll x[3], y[3];
    solver(s, x, y);
    printf("%lld %lld %lld %lld %lld %lld\n", x[0], y[0], x[1], y[1], x[2], y[2]);
}