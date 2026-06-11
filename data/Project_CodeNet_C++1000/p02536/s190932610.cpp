#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define PI 3.14159265358979323846

int Power(int a,int b)
{
    if(b == 0)
        return a;
    if(b &1)
        return a*Power(a,b-1);

    int t = Power(a,b/2);
    return t*t;
}

int GCD(int a,int b)
{
    if(b == 0)
        return a;
    return GCD(b,a%b);
}

void dfs(vector <int> graph[],bool visited[],int node,int n)
{
    visited[node] = true;

    for(int i=0;i<graph[node].size();i++)
    {
        int child = graph[node][i];
        if(!visited[child])
            dfs(graph,visited,child,n);
    }
    return;
}

void solve()
{
    int n,m;cin>>n>>m;
    vector <int> graph[n];

    while(m--)
    {
        int u,v;cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool visited[n];
    memset(visited,false,sizeof(visited));

    int connect = 0;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            connect++;
            dfs(graph,visited,i,n);
        }
    }
    connect--;
    cout<<connect;

    return;
}

int main()
{
   fast;

   int t;t = 1;
   while(t--)
    solve();

   return 0;

}


