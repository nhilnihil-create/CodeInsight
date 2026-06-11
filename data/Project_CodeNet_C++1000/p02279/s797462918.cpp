#include<stdio.h>
const int maxn=100005;
const int nil=-1;
struct shu
{
    int p,z,y;
};
shu T[maxn];
int n,D[maxn];
void Printf(int u)
{
    int i,c;
    printf("node %d:",u);
    printf(" parent = %d, ",T[u].p);
    printf("depth = %d, ",D[u]);
    if(T[u].p==nil) printf("root, ");
    else if(T[u].z==nil) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    for (i=0,c=T[u].z;c!=nil;i++,c=T[c].y)
    {
        if(i) printf(", ");
    printf("%d",c);
    }
    printf("]\n");
}
void deapth(int u,int p)
{
    D[u]=p;
    if(T[u].y!=nil) deapth(T[u].y,p);
    if(T[u].z!=nil) deapth(T[u].z,p+1);
}
int main()
{
    int u,d,c,r,huan;
    scanf("%d",&n);
    for (int i=0;i<n;i++) T[i].p=T[i].z=T[i].y=nil;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&u,&d);
        for (int j=0;j<d;j++)
        {
            scanf("%d",&c);
            if(j==0) T[u].z=c;
            else T[huan].y=c;
            huan=c;
            T[c].p=u;
        }
    }
    for (int i=0;i<n;i++)
        if(T[i].p==nil) r=i;
    deapth(r,0);
    for (int i=0;i<n;i++) Printf(i);
    return 0;
}