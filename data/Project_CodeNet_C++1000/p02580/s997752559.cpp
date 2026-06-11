#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    ll h,w,m;
    cin>>h>>w>>m;
    vector<ll> t_rows(h + 1, 0);
    vector<ll> t_cols(w + 1, 0);
    ll maxi_r = -1, maxi_c = -1;
    map< pi, int>dict;
    for (ll i = 0; i < m; i++)
    {
        ll a,b;
        cin>>a>>b;
        t_rows[a]++;
        maxi_r = max(maxi_r, t_rows[a]);
        t_cols[b]++;
        maxi_c = max(maxi_c, t_cols[b]);
        dict[make_pair(a,b)] = 1;
    }
    vector<ll> r,c;
    for(ll i=1; i<=w; i++)
    {
        if(t_cols[i] == maxi_c)
            c.push_back(i);
    }
    for(ll i=1; i<=h; i++)
    {
        if(t_rows[i] == maxi_r)
            r.push_back(i);
    }
    ll ans = maxi_c + maxi_r;
    for(ll i=0; i<r.size(); i++)
    {
        for (ll j = 0; j < c.size(); j++)
        {
            if(!dict[make_pair(r[i], c[j])])
            {
                cout<<ans<<'\n';
                return 0;
            }
        }    
    }
    cout<<ans - 1<<'\n';
}