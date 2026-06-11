#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define N 1010
#define Max 0x3f3f3f3f
int n, m, x;
int maps[N][N], dis[N],  vis[N];
int dij(int x)
{
    int i, j, pos, Min, sum=0;
    for(i=0; i<=n; i++)
    {
        dis[i]=maps[i][x];
        vis[i]=0;
    }
    for(i=0; i<=n; i++)
    {
        Min=Max;
        for(j=0; j<=n; j++)
        {
            if(vis[j]==0 && dis[j]<Min)
            {
                pos=j;
                Min=dis[j];
            }
        }
        vis[pos]=1;
        for(j=0; j<=n; j++)
        {
            if(vis[j]==0 && dis[j]>maps[j][pos]+dis[pos])
                dis[j]=maps[j][pos]+dis[pos];
        }
    }
    for(i=0; i<=n; i++)
    {
        sum+=dis[i];
    }
    return sum;

}
int main()
{
    int i, j, a, b, c, MAX, ans, p;
    while(scanf("%d",&m), m)
    {
        n=0;
        memset(maps, Max, sizeof(maps));
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(n<b)
                n=b;;
            maps[a][b]=maps[b][a]=min(maps[a][b], c);
        }
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==j)
                    maps[i][j]=0;
            }
        }
        MAX=Max;
        for(i=0;i<=n;i++)
        {

            ans=dij(i);
            if(MAX>ans)
            {
                p=i;
                MAX=ans;
            }
        }
        printf("%d %d\n", p, MAX);

    }
    return 0;
}