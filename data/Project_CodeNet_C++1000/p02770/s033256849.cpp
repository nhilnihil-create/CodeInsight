#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn=5010;
int k,q,d[maxn],n,x,m,a[maxn];
int main()
{
	scanf("%d%d",&k,&q);
	for (int i=1;i<=k;i++) scanf("%d",&d[i]);
	for (int _=1;_<=q;_++)
	{
		scanf("%d%d%d",&n,&x,&m); int sum0=0,t=n; long long sum=0;
		n--;
		for (int i=1;i<=k;i++) 
		{
			a[i]=d[i]%m; sum+=a[i];
			if (a[i]==0) sum0++;
		}
		sum=sum*(n/k); sum0=sum0*(n/k); n=n-(n/k)*k;
		for (int i=1;i<=n;i++) 
		{
			if (a[i]==0) sum0++;
			sum+=a[i];
		}
		sum+=(x%m); printf("%lld\n",t-1-sum0-sum/m);
	}
return 0;
}