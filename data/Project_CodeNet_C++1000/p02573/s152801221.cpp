#include<bits/stdc++.h>
#define ll long long
#define debug(x) {cerr<<#x<<" = "<<(x)<<endl;}
#define M(x) memset(x,0,sizeof(x))
#define dalao main
using namespace std;
vector<int>v[200005];
bool vis[200005];
int ans=-1;

int dfs(int s,int num)
{
    for(int i=0;i<v[s].size();i++)
    {
        int nxt=v[s][i];
        if(!vis[nxt])
        {
            vis[nxt]=true;
            num=dfs(nxt,num+1);
        }
    }
    return num;
}

int dalao()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            //debug(i)
            //debug(dfs(i,1));
            ans=max(ans,dfs(i,1));
        }
    }
    cout<<ans;
    return 0;
}
