#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10010
using namespace std;
int n,q;
int father[maxn];
int rank[maxn];

void init()
{
    for(int i=0; i<n; ++i)
    {
        father[i]=i;
        rank[i]=0;
    }
}

int find(int x)
{
    if(father[x]==x)
        return x;
    else
        return father[x]=find(father[x]);
}

void same(int x,int y)
{
	if(find(x)==find(y))
	  printf("1\n");
	else
	  printf("0\n");
}

void unite(int x,int y)
{
	father[find(x)]=find(y);
}

int main()
{
    scanf("%d%d",&n,&q);
    init();
    for(int i=0; i<q; ++i)
    {
        int com,x,y;
        scanf("%d%d%d",&com,&x,&y);
        if(com)
            same(x,y);
        else
            unite(x,y);
    }
    return 0;
}