#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;
ll a[200005];
ll b[200005];

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);
    ll mn, mx;
    if(n % 2 == 1)
    {
        mn = a[(n - 1) / 2];
        mx = b[(n - 1) / 2];
    }
    else
    {
        mn = a[n / 2] + a[n / 2 - 1];
        mx = b[n / 2] + b[n / 2 - 1];
    }
    printf("%lld\n", mx - mn + 1);
    return 0;
}
