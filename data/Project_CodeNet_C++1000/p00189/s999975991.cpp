#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

#define N 150
int inf=99999999;
int e[N][N];
int mark[N];
int m;
void init(int n)
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
        {
            if(i==j)e[i][j]=0;
            else
                e[i][j]=inf;
        }
}

void floyd(int n)
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            for(int k=0; k<=n; k++)
            {
                    if(e[j][k]>e[j][i]+e[i][k])
                    {
                        e[j][k]=e[j][i]+e[i][k];
                    }
            }
}

int main()
{
    while(scanf("%d",&m),m!=0)
    {
        int n=-1;
        int a,b,c;
        init(150);
        memset(mark,0,sizeof(mark));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            e[a][b]=e[b][a]=c;
            if(a>n)n=a;
            if(b>n)n=b;
            mark[a]=1;
            mark[b]=1;
        }

        floyd(n);
        int ans1,ans2;
        ans1=ans2=inf;
        for(int i=0; i<=n; i++)
        {
            int sum=0;
            if(mark[i]==1)
            {

                for(int j=0; j<=n; j++)
                {
                    if(mark[j]==1&&e[i][j]!=inf)
                    {
                        sum+=e[i][j];
                    }
                }
            }
            if(sum<ans2)
            {
                ans2=sum;
                ans1=i;
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}