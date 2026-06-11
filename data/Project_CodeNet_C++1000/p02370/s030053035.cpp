#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
#define INF (2e9)
const int maxv=10000+10;
const int maxe=100000+10;
int V,E;

int vis[maxv];
list<int> out;
vector<int> g[maxv];
int indege[maxv];
void bfs(int s)
{
    queue<int> que;
    que.push(s);
    while(!que.empty())
    {
        int u=que.front();que.pop();
        out.push_back(u);
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            indege[v]--;
            if(!vis[v]&&indege[v]==0)
            {
                vis[v]=1;
                que.push(v);

            }
        }
    }
}
void top_sort()
{
    memset(vis,0,sizeof(vis));
    memset(indege,0,sizeof(indege));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            int v=g[i][j];
            indege[v]++;
        }
    }
    for(int i=0;i<V;i++)
    {
        if(!vis[i]&&indege[i]==0)
        {
            bfs(i);
        }
    }
    for(list<int>::iterator iter=out.begin();iter!=out.end();iter++)
    {
        printf("%d\n",*iter);
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&V,&E);
    int u,v;
    for(int i=0; i<E; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    top_sort();
    return 0;
}