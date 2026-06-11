#include<bits/stdc++.h>
using namespace std;

int vis[100005],mx=-9;
map<int,map<int,int> >mp;
vector<int>adj[100005];

void dfs(int src,int par,int clr)
{
    vis[src]=1;  if(clr>mx)mx=clr;
    mp[par][src]=clr; mp[src][par]=clr; int p=0; int sz=adj[src].size();

    for(int lp=0;lp<sz;lp++)
    {
        int u=adj[src][lp];

        if(vis[u]==0)
        {
            p++; if(p==clr)p++;

            dfs(u,src,p);

        }

    }


}

int main()
{

    int n,m,i,j,k,a,b;
    vector< pair<int,int> >vct;

    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);  adj[a].push_back(b); adj[b].push_back(a);
        vct.push_back(make_pair(a,b));
    }

    dfs(1,-1,-1);

    printf("%d\n",mx);

    for(i=1;i<=n-1;i++)
    {
        a=vct[i-1].first; b=vct[i-1].second; printf("%d\n",mp[a][b]);
    }



    return 0;
}
