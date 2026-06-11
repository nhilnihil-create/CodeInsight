/* GRL_4_B */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<list>
#include<queue>
#include<limits>
using namespace std;
const int maxn=100001;
const int Max_INF=numeric_limits<int>::max();
int n,m;
int indeg[maxn];                                //??\???
bool visited[maxn];
vector<int> G[maxn];
vector<int> out_put;

void topological_sort_bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        out_put.push_back(u);
        for(int i=0;i<G[u].size();++i)
        {
            int v=G[u][i];
            indeg[v]--;
            if(indeg[v] == 0 && !visited[v])
            {
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    memset(visited,0,sizeof(visited));
    memset(indeg,0,sizeof(indeg));
    for(int i=0;i<m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        indeg[v]++;
    }
    for(int u=0 ;u < n;++u)
      if(indeg[u] == 0 && !visited[u])
        topological_sort_bfs(u);
    int num=out_put.size();
    while(num)
    {
        printf("%d\n",out_put[out_put.size()-num]);
        num--;
    }
    return 0;
}