#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;
ll k;
ll a[305];
ll d[305][305];
ll ans = 4e18;

int main()
{
    scanf("%lld%lld", &n, &k);
    for(ll i = 1; i <= k; i++) d[0][i] = 4e18;
    for(ll i = 1; i <= n + 1; i++)
    {
        if(i <= n) scanf("%lld", &a[i]);
        for(ll j = 0; j <= k; j++)
        {
            d[i][j] = 4e18;
            for(ll l = 0; l <= min(j, i - 1); l++)
            {
                d[i][j] = min(d[i][j], d[i - l - 1][j - l] + max(0LL, a[i] - a[i - l - 1]));
            }
        }
    }
    for(ll i = 0; i <= k; i++)
    {
        ans = min(ans, d[n + 1][i]);
    }
    printf("%lld\n", ans);
    return 0;
}
