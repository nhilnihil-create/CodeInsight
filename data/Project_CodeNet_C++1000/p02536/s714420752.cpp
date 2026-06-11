#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mod 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define setpres(x) fixed<<setprecision(x)
using namespace std;
vector<int> v[100001];
bool vis[100001];
void dfs(int s)
{
    vis[s]=1;
    for(auto x:v[s])
    {
        if(!vis[x])
            dfs(x);
    }
}
int32_t main()
{
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        int cc=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                dfs(i), cc++;
        }
        cout<<cc-1;
    }
}

