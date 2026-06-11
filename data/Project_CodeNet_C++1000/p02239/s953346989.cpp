#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define white 0
#define black -1
#define grey 1
#define infly 1<<21
using namespace std;
int a[110][110],n;
int d[110];
int color[110];

void bfs()
{
    memset(d,0,sizeof(d));
    queue<int> Q;
    for(int i=1;i<=n;i++)
        d[i]=infly;
    d[1]=0;
    for(int i=1;i<=100;i++)
        color[i]=white;
    Q.push(1);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=1;i<=n;i++)
        {
            if(a[u][i]==0)
                continue;
            if(d[i]!=infly)
                continue;
                Q.push(i);
                d[i]=d[u]+1;
        }
    }
    for(int i=1;i<=n;i++)
   {
       cout<<i<<" "<<((d[i]==infly)?(-1):d[i])<<endl;
   }

}

int main()
{
   int key,d,x;
   memset(a,0,sizeof(a));
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       scanf("%d%d",&key,&d);
       for(int j=1;j<=d;j++)
       {
        scanf("%d",&x);
        a[key][x]=1;
       }
   }
   bfs();
   return 0;
}