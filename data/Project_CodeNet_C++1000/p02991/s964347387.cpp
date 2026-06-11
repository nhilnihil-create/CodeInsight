#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+5;
vector<int>E[maxn];
int d[maxn][3]; // mod 3=j
int vis[maxn][3];
void bfs(int x)
{
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<3;j++)
        {
            d[i][j]=1e9;
        }
    }
    queue<pair<int,int>>q;
    d[x][0]=0;
    vis[x][0]=1;
    q.push({x,0});
    while(!q.empty())
    {
        int now=q.front().first;
        int t=q.front().second;//这一步mod3的值
        int y=(t+1)%3;//下一步mod3的值
        q.pop();
        for(auto&v:E[now])
        {
            if(vis[v][y]) continue;
            vis[v][y]=1;
            d[v][y]=d[now][t]+1;
            q.push({v,y});
        }
    }

}
void dijkstra(int x)
{

}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=m;i++)
   {
       int u,v;
       cin>>u>>v;
       E[u].push_back(v);
   }
   int s,t;
   cin>>s>>t;
   bfs(s);
   if(d[t][0]==1e9)
   {
       cout<<-1<<'\n';
   }
   else
    cout<<d[t][0]/3<<'\n';



}









