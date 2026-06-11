#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

int n;
const int full=1000001;
vector<int>adj[full];
bool vis[full];
int par[full];
int depth[full];
ll h[full];
ll l[full];
void dfs(int i)
{
    vis[i]=1;
    for(int j=0;j<adj[i].size();j++)
    {
        if(h[i]<=h[adj[i][j]])
        {
           l[i]=1; 
        }
        if(vis[adj[i][j]]==0)
        {
            dfs(adj[i][j]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int i,j,k;
    int n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].push_back(a);
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }
    int c=0;
    for(i=1;i<=n;i++)
    {
        if(l[i]==0)
        {
            c++;
        }
    }
    cout<<c;
}