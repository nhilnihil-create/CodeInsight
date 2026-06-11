#include<bits/stdc++.h>
using namespace std;
#define  mem(a,x) memset(a,x,sizeof(a));
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
#define  B   begin()
#define  E   end()
const int N=1e5+3;
vector<int>v[N];
int vis[N];
void dfs(int f)
{
    vis[f]=1;
    for(int x:v[f])
    {
        if(vis[x]==-1)
        {
            dfs(x);
        }
    }
}
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>n>>m;
    mem(vis,-1);
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    l=0;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==-1)
        {
            l++;
            dfs(i);
        }
    }
    cout<<l-1<<"\n";
    return 0;
}

