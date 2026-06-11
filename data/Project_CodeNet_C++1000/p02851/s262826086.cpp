#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll n, k;
ll a[200005];
ll b[200005];
map<ll, ll> ma;
ll ans;

int main()
{
    scanf("%lld%lld", &n, &k);
    ma[0]++;
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i]--;
        b[i] = b[i - 1] + a[i];
        ma[b[i] % k]++;
        if(i >= k) ma[b[i - k] % k]--;
        ans += ma[b[i] % k] - 1;
    }
    printf("%lld\n", ans);
    return 0;
}
