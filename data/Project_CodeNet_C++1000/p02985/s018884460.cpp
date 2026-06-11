#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int st[100010];
vector<int> edge[100010];
int bro[100010],vis[100010],cnt[100010]; 
int n,k;
void dfs(int u,int fa,int deep)
{
    int w;
    if(deep<2)  w = deep+1;
    else
    {
        w = 2;
    }
    int x = edge[u].size();
    int bro = 0;
    for(int i=0;i<edge[u].size();i++)
    {
        int v = edge[u][i];
        if(v==fa) continue;
        cnt[v] = k-bro-w;
        bro++;
        dfs(v,u,deep+1);
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cnt[1] = k;
    dfs(1,0,0);
    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d ",bro[i]);
    // }
    long long ans = 1;
    for(int i=1;i<=n;i++)
    {
        ans = ans * cnt[i] % mod;
    }
    printf("%lld",ans);
    return 0;
}