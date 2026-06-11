#include<bits/stdc++.h>
using namespace std;
vector<int> vis(200001,0);
vector<int> sizee(200001,0);
int dfs(int x,vector<set<int> > &adj)
{
     vis[x]=1;
     int currsize=1;
     for(auto j:adj[x])
     {
         if(vis[j]==0)
         {
             currsize+=dfs(j,adj);
         }
     }
     sizee[x]=currsize;
     return currsize;
}
int main()
{

    int n,m;
    cin>>n>>m;
    vector<set<int> > adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<i<<"-> ";
        for(auto j:adj[i])
            cout<<j<<" ";
        cout<<endl;
    }*/
    int ans=0;
    for(int i=1;i<=n;i++)
    {

        if(vis[i]==0)
        {
            ans=max(ans,dfs(i,adj));
        }
    }
    cout<<ans<<endl;

}
