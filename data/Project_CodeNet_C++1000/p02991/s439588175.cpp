///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           node(a,b,c)                 mp(mp(a,b),c)
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=500005;
int n,m;
vector<int>adj[M];
int vis[M],dis[M];
 main()

{
    fast
    cin>>n>>m;
    f(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v+n);
        adj[u+n].pb(v+2*n);
        adj[u+2*n].pb(v);
    }
    int st,en;
    cin>>st>>en;
    queue<int>q;
    q.push(st);
    vis[st]=1;
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(vis[v])continue;
            vis[v]=1;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    if(vis[en]==0)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<dis[en]/3<<endl;
    }
    return 0;

}



































