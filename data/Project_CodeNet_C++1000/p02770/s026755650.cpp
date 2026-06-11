#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
ll d[100010];
int main()
{
    ll n, q;
    scanf("%lld%lld", &n, &q);
    for (int i = 0; i < n; i++)
    {

        scanf("%lld", &d[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        ll nn, x, m;
        scanf("%lld%lld%lld", &nn, &x, &m);
        ll tot = 0;
        ll ret = 0, ret1 = 0;
        for (int j = 0; j < n; j++)
        {
            if (d[j] % m == 0)
                ret++;
            tot = tot + d[j] % m;
        }
        ll ans = ((nn - 1) / n) * tot / m;
        ll nw = x % m + ((nn - 1) / n) * (tot % m) % m;
        for (int j = 0; j < (nn - 1) % n; j++)
        {
            if (d[j] % m == 0)
                ret1++;
            nw += d[j] % m;
        }
        ans += nw / m;
        printf("%lld\n", nn - 1 - ans - ret1 - ((nn - 1) / n) * ret);
    }
    return 0;
}