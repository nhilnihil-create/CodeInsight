#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
ll n, m;
ll a[2005], b[2005];
ll d[2005][2005], e[2005][2005];

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(ll i = 1; i <= m; i++) scanf("%lld", &b[i]);
    for(ll i = 1; i <= n + 1; i++)
    {
        for(ll j = 1; j <= m + 1; j++)
        {
            if(a[i] == b[j]) d[i][j] = e[i - 1][j - 1] + 1;
            e[i][j] = e[i][j - 1] + e[i - 1][j] - e[i - 1][j - 1] + d[i][j] + M;
            d[i][j] %= M;
            e[i][j] %= M;
        }
    }
    printf("%lld\n", d[n + 1][m + 1]);
    return 0;
}
