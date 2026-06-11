#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
ll n, m;
vector<ll> ve[100005];
ll ans = 1;
bool v[100005];

void dfs(ll p, ll q)
{
    if(m <= q)
    {
        cout<<0<<endl;
        exit(0);
    }
    ans *= (m - q);
    ans %= M;
    ll j = 0;
    for(ll i = 0; i < ve[p].size(); i++)
    {
        if(v[ve[p][i]]) {j = 1; continue;}
        v[ve[p][i]] = true;
        dfs(ve[p][i], i - j + 1 + (p != 1));
    }
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i < n - 1; i++)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        ve[t1].push_back(t2);
        ve[t2].push_back(t1);
    }
    v[1] = true;
    dfs(1, 0);
    cout<<ans<<endl;
    return 0;
}
