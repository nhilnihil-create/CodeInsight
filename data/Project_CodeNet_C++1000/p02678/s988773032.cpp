#include<bits/stdc++.h>
using namespace std;
vector<int> visited;
vector<vector<int> > adj;
vector<int> parent;
vector<int> dp;
int main()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1);
    parent.resize(n+1);
    dp.resize(n+1,1e7);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    dp[1]=0;
    visited[1]=1;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(auto it:adj[s])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
            if(dp[it]>=dp[s]+1)
            {
                parent[it]=s;
                dp[it]=dp[s]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<parent[i]<<endl;
    }
}