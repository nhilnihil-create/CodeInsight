#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define F first
#define S second

using namespace std;

typedef long long ll;

ll n;
ll a, b;
ll ans;
pair<ll, ll> x[105];

bool cmp(pair<ll, ll> p, pair<ll, ll> q)
{
    return atan2((double)p.S, (double)p.F) < atan2((double)q.S, (double)q.F);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld%lld", &x[i].F, &x[i].S);
    }
    sort(x, x + n, cmp);
    for(ll j = 0; j < n; j++)
    {
        a = b = 0;
        for(ll i = 0; i < n; i++)
        {
            a += x[(i + j) % n].F;
            b += x[(i + j) % n].S;
            ans = max(ans, a * a + b * b);
        }
    }
    printf("%.15f", sqrt((double)ans));
    return 0;
}
