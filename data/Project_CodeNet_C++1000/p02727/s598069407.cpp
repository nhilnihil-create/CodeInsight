# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
using namespace std;
struct Node{
    long long d;
    long long c;
}N[400010];
int cnt = 0;
bool cmp(struct Node a,struct Node b)
{
    if (a.d==b.d) return a.c<b.c;
    return a.d>b.d;
}
int main(void)
{
    // freopen("aaa.in","r",stdin);
    long long X,Y,A,B,C;
    scanf("%lld%lld%lld%lld%lld",&X,&Y,&A,&B,&C);
    for (int i=1;i<=A;i++)
    {
        N[++cnt].c = 1;
        scanf("%lld",&N[cnt].d);
    }
     for (int i=1;i<=B;i++)
    {
        N[++cnt].c = 2;
        scanf("%lld",&N[cnt].d);
    }
     for (int i=1;i<=C;i++)
    {
        N[++cnt].c = 3;
        scanf("%lld",&N[cnt].d);
    }
    sort(N+1,N+cnt+1,cmp);
    long long ans = 0;
    long long Z=0;
    for (int i=1;i<=cnt;i++)
    {
        if (N[i].c==1)
        {
            if (X){
                X--;
                ans+=N[i].d;
            }
        }
        if (N[i].c==2)
        {
            if (Y)
            {
                Y--;
                ans+=N[i].d;
            }
        }
        if (N[i].c==3)
        {
            if (X>0||Y>0){
                Z++;
                ans+=N[i].d;
            }
        }
        if (Z==X+Y) break;
    }
    printf("%lld\n",ans);
    return 0;
}