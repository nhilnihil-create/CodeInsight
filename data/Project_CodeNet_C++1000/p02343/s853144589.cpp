#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=10000+5;
int n,q;
int p[maxn],r[maxn];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int fnd(int x)
{
    if(x==p[x]) return x;
    return p[x]=fnd(p[x]);
}
bool is_same(int x,int y)
{
    x=fnd(x);
    y=fnd(y);
    return x==y;
}
void unite(int x,int y)
{
    x=fnd(x);
    y=fnd(y);
    if(r[x]>r[y])
    {
        p[y]=x;
    }
    else
    {
        p[x]=y;
        if(r[x]==r[y]) r[y]++;
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&q);
    int op,x,y;
    init(n);
    while(q--)
    {
        scanf("%d%d%d",&op,&x,&y);
        switch(op)
        {
        case 0:
            {
                unite(x,y);
                break;
            }
        case 1:
            {
               printf("%d\n",is_same(x,y)?1:0);

                break;
            }
        }
    }
    return 0;

}