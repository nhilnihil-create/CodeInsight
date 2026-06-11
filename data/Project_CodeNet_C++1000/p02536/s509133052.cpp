#include <bits/stdc++.h>
#include<functional>
#include<stdio.h>
using namespace std;
#define int long long
void dfs(int x,vector<int>v[],bool vis[])
{
    if(vis[x]==false)
        vis[x]=true;
    for(int i=0;i<v[x].size();i++)
    {
        if(vis[v[x][i]]==false)
        {
            vis[v[x][i]]=true;
            dfs(v[x][i],v,vis);
        }
    }
}
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v[n+1];
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool vis[n+1];
    memset(vis,0,sizeof(vis));
    int con=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
        dfs(i,v,vis);
        con++;
        }
    }
    cout<<con-1<<endl;
}
