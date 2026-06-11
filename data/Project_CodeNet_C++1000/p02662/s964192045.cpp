#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 998244353;

ll n, s;
ll a[3005];
ll d[3005];

int main()
{
    scanf("%lld%lld", &n, &s);
    d[0] = 1;
    for(ll i = 0; i < n; i++)
    {
        ll t;
        scanf("%lld", &t);
        for(ll j = s; j >= 0; j--)
        {
            d[j] *= 2;
            if(j >= t) d[j] += d[j - t];
            d[j] %= M;
        }
    }
    printf("%lld\n", d[s]);
    return 0;
}
