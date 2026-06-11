#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(n) scanf("%lld", &n)
#define pcl(n) printf("%lld\n", n)
#define pcl1(n) printf("%lld ", n)
#define dev(x) cout << #x << " " << x << " ";
#define PTT pair<ll, ll>

map<ll, ll> mp, mp1;
map<ll, ll>::iterator itr;
ll rem[2019];

int main()
{
    ll l, r;
    scl(l);
    scl(r);

    for (ll i = l; i <= min(r, l + 2019); i++)
    {
        rem[i % 2019]++;
    }
    ll mn = 1e10;
    for (ll i = 0; i < 2019; i++)
    {
        for (ll j = i + 1; j < 2019; j++)
        {
            if (rem[i] && rem[j])
            {
                mn = min(mn, (i * j) % 2019);
            }
        }
    }
    cout << mn << endl;

    return 0;
}
