#include<stdio.h>
#include<fstream>
#include<algorithm>
using namespace std;
struct jiedian
{
 int fu,left,right,shengdu;
}a[2000005];
const int null=-1;
void res(int u,int p)
{
    a[u].shengdu=p;
    if(a[u].right!=null) res(a[u].right,p);
    if(a[u].left!=null) res(a[u].left,p+1);
}

int main()
{

    int n;int p;int k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a[i].fu=a[i].left=a[i].right=null;
    }

    for(int i=0;i<n;i++)
    {
        int node,du;
        scanf("%d%d",&node,&du);
        for(int j=0;j<du;j++)
        {
            scanf("%d",&k);
            if(j==0)  a[node].left=k;
            else
            a[p].right=k;
             p=k;
             a[k].fu=node;
        }
    }
    /*for(int i=0;i<n;i++)
    {
        printf("%d %d %d\n",a[i].fu,a[i].left,a[i].right);
    }*/
    int hd;
    for(int i=0;i<n;i++)
    {
        if(a[i].fu==null) hd=i;
    }
    res(hd,0);
    for(int i=0;i<n;i++)
    {
       // printf("node %d: parent = %d, depth = %d, ",i,a[i].fu,a[i].shengdu);
          printf("node %d: ",i);
          printf("parent = %d, ",a[i].fu);
          printf("depth = %d, ",a[i].shengdu);
            if(a[i].fu==null) printf("root, ");
            else if(a[i].left==null) printf("leaf, ");
            else printf("internal node, ");
            printf("[");
           //printf("%d ",a[i].left);
       for(int j=0,c=a[i].left;c!=null;j++,c=a[c].right)
        {
        if(j) printf(", ");
        printf("%d",c);
        }
           printf("]\n");


    }
return 0;
}