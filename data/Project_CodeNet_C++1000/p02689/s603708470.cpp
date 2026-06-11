/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mod   998244353
#define PI 2*acos(0.0)
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};

ll bigmod(ll x, ll p)
{
    ll res = 1;
    while(p)
    {
        if(p&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        p >>= 1;
    }
    return res;
}

//=============================================ASIFAZAD==============================================//

int32_t main()
{
    io;
    int n, m;
    cin>>n>>m;
    vi val(n), cnt(n);
    for(auto& x: val) cin>>x;

    vector<bool> vis(n);
    vi adj[n];

    while(m--)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<int> q;

    for(int i = 0; i < n;i++)
    {
        if(vis[i])
            continue;
        q.push(i);
        vis[i] = 1;
        while(!q.empty())
        {
            int nod = q.front();
            q.pop();
            for(auto x: adj[nod])
            {
                if(val[x] == val[nod])
                    {
                        //cout<<"a\n";
                        cnt[x]++;
                        cnt[nod]++;
                    }
                    else if(val[x] > val[nod])
                    {
                        cnt[nod]++;
                        //cout<<"b\n";
                    }
                    else
                    {
                        cnt[x]++;
                        //cout<<"c\n";
                    }

                if(!vis[x])
                {
                    vis[x] = 1;
                    //cout<<"cntn " << cnt[nod] <<" cntx: " << cnt[x]<<"\n";
                    q.push(x);
                }
            }
        }
    }

    int ans = 0;
    for(int i =0 ;i < n; i++)
        if(!cnt[i])
            ans++;
    cout<<ans;
    return 0;
}
