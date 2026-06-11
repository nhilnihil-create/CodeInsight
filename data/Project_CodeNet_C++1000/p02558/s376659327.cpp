#include <atcoder/all>
#include "bits/stdc++.h"
using namespace std;
using namespace atcoder;

int n,q,t,u,v;

int main()
{
	scanf("%d%d",&n,&q);
	auto ds=dsu(n);
	while(q--)
	{
		scanf("%d%d%d",&t,&u,&v);
		if(t==0) ds.merge(u,v);
		else printf("%d\n",ds.same(u,v));
	}
}