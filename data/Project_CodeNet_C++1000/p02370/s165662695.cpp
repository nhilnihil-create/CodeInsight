#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
#define maxn 10000
vector<int> G[maxn+10],ans;
queue<int> q;
int biao[maxn+10];
int color[maxn+10];
void bfs(int s)
{
    q.push(s);
    color[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for (int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            biao[v]--;
            if(!color[v]&&biao[v]==0)
            {
                color[v]=true;
                q.push(v);
            }
        }
    }
}
int main()
{
    int u,v;
    scanf("%d%d",&u,&v);
    int x,y;
    for (int i=0;i<v;i++)
    {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
    }
    for(int i=0;i<u;i++)
    {
        for (int j=0;j<G[i].size();j++)
            biao[G[i][j]]++;
    }
    for (int i=0;i<u;i++)
    {
        if(biao[i]==0&&!color[i])
            bfs(i);
    }
    for (int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
    return 0;
}