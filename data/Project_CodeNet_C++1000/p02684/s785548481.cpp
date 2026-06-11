#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N=200001;
bool vis[N];
vector<int> adj[N];
int cyclr(int x)
{
    while(!vis[x])
    {
        vis[x]=1;
        x = adj[x][0];
    }
    return x;
}
int sizlo(int x)
{
    int s=x;
    int c=0;
    do
    {
        x = adj[x][0];
        c++;
    }
    while(x!=s);

    return c;
}
int dfs(int x, int k,int cyc)
{
   while(x!=cyc && k>0)
   {
       x = adj[x][0];
       k--;
   }
   if(x!=cyc)
   return x;

    k = k%sizlo(cyc);
    while(k>0)
   {
       x = adj[x][0];
       k--;
   }
    return x;
}
signed main() {
    ios_base::sync_with_stdio(1);
    cin.tie(0);
    cout.tie(0);
    int n,k,t;
    cin>>n>>k;
    //vector<int> arr(n+1);

    //vector<int> adj[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>t;
        adj[i+1].push_back(t);
    }
    int cyc = cyclr(1);
    cout<<dfs(1,k,cyc);

    return 0;
}