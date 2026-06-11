#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const ll M = 4e18;
ll n, m;
ll a[100005];
vector<ll> ans;

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i <= n; i++)
    {
        scanf("%1lld", &a[i]);
    }
    ll t = n;
    while(t > 0)
    {
        ll mn = M;
        for(ll i = 1; i <= min(m, t); i++)
        {
            if(a[t - i] == 0) mn = t - i;
        }
        if(mn == M)
        {
            printf("-1\n");
            return 0;
        }
        ans.push_back(t - mn);
        t = mn;
    }
    for(ll i = ans.size() - 1; i >= 0; i--)
    {
        printf("%lld ", ans[i]);
    }
    return 0;
}
