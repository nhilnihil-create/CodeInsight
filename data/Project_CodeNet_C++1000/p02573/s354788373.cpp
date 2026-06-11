#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define set_bits(a) __builtin_popcount(a)
#define pb push_back
#define pf push_front
#define mod 1000000007
#define M 998244353
#define mp unordered_map
#define fi first
#define se second
#define endl '\n'
#define INF 1e18
#define PI 3.14159265358979323846
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    ll n,m,i,j;
    cin>>n>>m;

    vector<ll>adj[n];

    unordered_map<ll, vector<ll> >mp;

    for(i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bool vis[n];
    memset(vis,false,sizeof(vis));
    ll x=1;

    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            queue<ll>q;
            q.push(i);
            vis[i]=true;
            mp[x].pb(i);

            while(!q.empty())
            {
                ll p = q.front();
                q.pop();
                for(j=0;j<adj[p].size();j++)
                {
                    if(!vis[adj[p][j]])
                    {
                        q.push(adj[p][j]);
                        vis[adj[p][j]]=true;
                        mp[x].pb(adj[p][j]);
                    }
                }
            }
            x++;
        }
    }

    ll ans = -1;

    for(auto it:mp)
    {
        vector<ll>v = it.se;
//        for(i=0;i<v.size();i++)
//        {
//            cout<<v[i]<<" ";
//        }
        n = v.size();
        ans = max(ans,n);
    }
    cout<<ans<<endl;
}
