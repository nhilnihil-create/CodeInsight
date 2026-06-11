#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<ctype.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
#define oo 0x3f3f3f3f
#define maxn 1010

int maps[maxn][maxn];
int dis[maxn];
int vis[maxn];
int m;

void Init(int n)
{
    for(int i=0;i<=n+2;i++)
    {
        for(int j=0;j<=n+2;j++)
        {
            if(i==j)
                maps[i][j]=0;
            else
                maps[i][j]=oo;
        }
    }
}

int dij(int pos)
{
    int Min;
    int s=pos;
    for(int i=0;i<=m;i++)
        {
            dis[i]=maps[pos][i];

            vis[i]=0;
        }

    vis[pos]=1;
    for(int i=0;i<m;i++)
    {
        Min=oo;
        for(int j=0;j<=m;j++)
        {
            if(!vis[j] && Min>dis[j])
            {
                Min=dis[j];
                pos=j;
            }
        }

        vis[pos]=1;
        for(int j=0;j<=m;j++)
        {
            if(!vis[j] && dis[j] > Min+maps[pos][j])
                dis[j]=Min+maps[pos][j];
        }
    }
    int sum=0;
    for(int i=0;i<=m;i++)
        sum+=dis[i];
    return sum;

}

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        Init(n);
        int a,b,c;
        m=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            maps[a][b]=maps[b][a]=min(c,maps[a][b]);
            m=max(max(a,b),m);
        }
        int ans=oo,k=0;
        for(int i=0;i<=m;i++)
        {
            int q=dij(i);

            if(q<ans)
            {
                ans=q;
                k=i;
            }
        }
        printf("%d %d\n",k,ans);
    }
    return 0;
}