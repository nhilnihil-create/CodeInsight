//No matter what happens in your life, believe in yourself.
#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int mod=1e9+7;
const int inf=-1;
const int sz=1e5+2;

#define pi acos(-1)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define gap ' '
#define lb lower_bound
#define ub upper_bound
#define SIN(x) sin(x * pi / 180.0)
#define COS(x) cos(x * pi / 180.0)
#define popcnt(x) __builtin_popcount(x)
#define clr(x) memset(x,0,sizeof(x))
#define all(x) sort(x.begin(),x.end())
#define rall(x) reverse(x.begin(),x.end())
#define dbg puts("finding wrong")
#define case(x,y) printf("Case %lld: %lld\n",++x,y)
#define fastio ios::sync_with_stdio(false);cin.tie(0)

vector<int>adj[sz];
int vis[sz];

void bfs(int s)
{
    queue<int>q;

    q.push(s);
    vis[s]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<(int)adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
void add(int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

signed main()
{
    int n, m, i, u, v;
    cin>>n>>m;
    for(i=1; i<=n; i++)vis[i]=0;
    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        add(u,v);
    }
    int cnt=0;
    for(i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            bfs(i);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
}
