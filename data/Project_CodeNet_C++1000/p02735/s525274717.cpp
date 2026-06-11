#include <bits/stdc++.h>
using namespace std;
#define Maxn 107
#define inf 1000007
char s[Maxn][Maxn];
int last[1000007],pre[1000007],other[1000007],len[1000007],cnt=0;
int n,m;
int calc(int x,int y)
{
    return (x-1)*m+y;
}
void insert(int u,int v,int l)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
    len[cnt]=l;
}
int dis[1000007];
bool vis[1000007];
priority_queue<pair<int,int> >que;
int dijkstra(int s,int t)
{
    for (int i=1;i<=t;i++)
        dis[i]=inf;
    memset(vis,false,sizeof(vis));
    while (!que.empty()) que.pop();
    que.push(make_pair(0,s));
    dis[s]=0;
    while (!que.empty())
    {
        int u=que.top().second;
        que.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int q=last[u];q;q=pre[q])
        {
            int v=other[q];
            if (dis[v]>dis[u]+len[q])
            {
                dis[v]=dis[u]+len[q];
                que.push(make_pair(-dis[v],v));
            }
        }
    }
    return dis[t];
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (i<n)
            {
                int tmp=0;
                if (s[i][j]=='.'&&s[i][j]!=s[i+1][j]) tmp=1;
                insert(calc(i,j),calc(i+1,j),tmp);
            }
            if (j<m)
            {
                int tmp=0;
                if (s[i][j]=='.'&&s[i][j]!=s[i][j+1]) tmp=1;
                insert(calc(i,j),calc(i,j+1),tmp);
            }
        }
    int S=n*m+1,T=n*m+2;
    if (s[1][1]=='.') insert(S,calc(1,1),0); else insert(S,calc(1,1),1);
    insert(calc(n,m),T,0);
    printf("%d\n",dijkstra(S,T));
    return 0;
}