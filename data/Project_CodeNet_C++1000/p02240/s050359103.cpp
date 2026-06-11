#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int INF=1<<21;
const int maxn=100000+10;
int n,m,q;
int p[maxn];
int rank[maxn];
void init(int n)
{
   for(int i=0;i<n;i++)
   {
       p[i]=i;
       rank[i]=0;
   }
}
int fnd(int x)
{
    if(x==p[x]) return x;
    return fnd(p[x]);
}
bool is_same(int x,int y)
{
   return fnd(x)==fnd(y);
}

void uni(int x,int y)
{
   x=fnd(x);
   y=fnd(y);
   if(rank[x]>rank[y])
   {
       p[y]=x;
   }
   else
   {
       p[x]=y;
       if(rank[x]==rank[y]) rank[y]++;
   }
}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int x,y;
    init(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        uni(x,y);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&x,&y);
        if(is_same(x,y)) printf("yes\n");
        else printf("no\n");
    }


    return 0;
}