#include <atcoder/fenwicktree>
#include "bits/stdc++.h"
using namespace std;
using namespace atcoder;

const int N=2e5+20;

int n,q,t,u,v;

int main()
{
	scanf("%d%d",&n,&q);
	auto dsa=fenwick_tree<long long>(n);
  	for(int i=0;i<n;i++) scanf("%d",&u),dsa.add(i,u);

	while(q--)
	{
		scanf("%d%d%d",&t,&u,&v);
		if(t==0) dsa.add(u,v);
		else printf("%lld\n",dsa.sum(u,v));
	}
}