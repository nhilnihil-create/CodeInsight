#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll n;
ll a[100005];
ll ans;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    for(ll i = 1; i < n - 1; i++)
    {
        ans += abs(a[i]);
    }
    ans += a[n - 1] - a[0];
    printf("%lld\n", ans);
    for(ll i = 1; i < n - 1; i++)
    {
        if(a[i] > 0) printf("%lld %lld\n", a[0], a[i]), a[0] -= a[i];
        else printf("%lld %lld\n", a[n - 1], a[i]), a[n - 1] -= a[i];
    }
    printf("%lld %lld\n", a[n - 1], a[0]);
    return 0;
}
