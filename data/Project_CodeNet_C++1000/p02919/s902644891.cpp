#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int M=1e5+5;
int id[M];
struct Node
{
	int p;
	int l,r;
	void read(int i)
	{
		l=i-1;
		r=i+1;
		scanf("%d",&p);
		id[p]=i;
	}
}node[M];
void link(int l,int r)
{
	node[l].r=r;
	node[r].l=l;
}

int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)
		node[i].read(i);
	link(0,1); link(n,n+1);
	LL ans=0;
	for(int i=1;i<n;i++)
	{
		int u=id[i];
		int l=node[u].l,r=node[u].r;
		if(l)
			ans+=((LL)l-node[l].l)*((LL)r-u)*i;
		if(r!=n+1)
			ans+=((LL)node[r].r-r)*((LL)u-l)*i;
		link(l,r);
	}
	printf("%lld\n",ans);
}