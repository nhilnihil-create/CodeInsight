#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll g(ll n, int p)
{
    if (n == 0)
        return 0;
    return g(n / p, p) + n / p;
}

ll g2(ll n, int p)
{
    ll ret = g(n / 2, p);
    if (p == 2)
        ret += n / 2;
    return ret;
}

int main()
{
    ll n;
    cin >> n;

    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    ll ans = min(g2(n, 2), g2(n, 5));
    cout << ans << endl;

    return 0;
}