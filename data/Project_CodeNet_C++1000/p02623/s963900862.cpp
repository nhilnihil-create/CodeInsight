#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll a[200005], b[200005];
ll n, m, k;

void solve()
{
    cin >> n >> m >> k;
    ll asum = 0, bsum = 0;
    for(int i = 1; i<=n; i++)
    {
        int c;
        cin >> c;
        asum += c;
        a[i] = asum;
    }
    for(int i = 1; i<=m; i++)
    {
        int c;
        cin >> c;
        bsum += c;
        b[i] = bsum;
    }
    ll total = 0;
    for(ll i=0; i<=n; i++)
    {
        ll other = k-a[i];
        if(other<0)
            continue;
        int l=lower_bound(b, b+m, other)-begin(b);
        if(l>m || b[l]>other)
            --l;
        total=max(total, i+l);
    }
    cout <<total;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
