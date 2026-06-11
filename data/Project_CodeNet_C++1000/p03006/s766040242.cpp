#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#define F first
#define S second

using namespace std;

typedef long long ll;

ll n;
ll a[55];
ll b[55];
map<pair<ll, ll>, ll> ma;
ll ans;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        for(ll j = 0; j < i; j++)
        {
            if(a[i] > a[j]) ma[make_pair(a[i] - a[j], b[i] - b[j])]++;
            else if(a[i] == a[j]) ma[make_pair(0, abs(b[i] - b[j]))]++;
            else ma[make_pair(a[j] - a[i], b[j] - b[i])]++;
        }
    }
    for(auto i:ma)
    {
        ans = max(ans, i.S);
    }
    printf("%lld\n", n - ans);
    return 0;
}
