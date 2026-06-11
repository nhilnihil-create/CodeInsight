#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e3;
int d[N+100];

int main()
{
	int k,q;
	scanf("%d%d",&k,&q);
	for(int i=1;i<=k;i++){
		scanf("%d",d+i);
	}
	while(q--)
	{
		ll n,x,m;
		scanf("%lld%lld%lld",&n,&x,&m);
		ll e = x%m;
		ll neg = 0;
		//printf("%lld ",e);
		for(int i=1;i<=k;i++){
			ll cur = d[i]%m;
			ll div = (n-1)/k;
			if((n-1)%k>=i){
				div++;
			}
			if(cur==0){
				neg += div;
			}
			e += div*cur;
		}
		printf("%lld\n",n-1-e/m-neg);
	}
}
