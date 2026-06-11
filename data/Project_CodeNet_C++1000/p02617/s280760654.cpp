#include "bits/stdc++.h"
using namespace std;

int n,u,v;
long long ans;

int main()
{
	scanf("%d",&n);

	for(int i=1;i<=n;i++) ans+=1ll*i*(n-i+1);

	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		ans-=1ll*u*(n-v+1);
	}
	printf("%lld",ans);
}