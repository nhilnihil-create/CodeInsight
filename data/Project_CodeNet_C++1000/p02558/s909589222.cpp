#include <atcoder/dsu>
#include "bits/stdc++.h"
using namespace std;
using namespace atcoder;

const int N=2e5+20;

int n,q,t,u,v,c;

int main()
{
	scanf("%d%d",&n,&q);
	auto dsa=dsu(n);
	while(q--)
	{
		scanf("%d%d%d",&t,&u,&v);
		if(t==0) dsa.merge(u,v);
		else printf("%d\n",dsa.same(u,v));
	}
}