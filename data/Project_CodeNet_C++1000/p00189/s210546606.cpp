#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF=99999999;

int ma[11][11];
int dis[11][11];
int maxx,id,ans;

int slove()
{
    for(int k=0;k<=maxx;k++)
        for(int i=0;i<=maxx;i++)
            for(int j=0;j<=maxx;j++)
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    ans = INF;
    for(int i=0;i<=maxx;i++)
    {
        int sum=0;
        for(int j=0;j<=maxx;j++)
            sum+=dis[i][j];
        if(ans > sum){
            ans = sum;
            id = i;
        }
    }
}

int main()
{
    int t;
    while(scanf("%d",&t)&&t)
    {
        for(int i=0;i<=11;i++)
            for(int j=0;j<=11;j++)
            if(i != j)dis[i][j] = INF;
        maxx=0;
        while(t--)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            dis[a][b]=c;
            dis[b][a]=c;
            maxx=max(maxx,max(a,b));
        }
        slove();
        cout<<id<<" "<<ans<<endl;
    }
}

