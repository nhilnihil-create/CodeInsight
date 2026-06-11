#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2<<17;
int n;ll a[N],b[N],ans;
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	for(int t=0;t<500;t++)
		for(int i=t&1;i<n;i+=2)
		{
			ll s=b[(i+n-1)%n]+b[(i+1)%n];
			ll t=(b[i]-a[i])/s;
			ans+=t;
			b[i]-=t*s;
		}
	for(int i=0;i<n;i++)
		if(a[i]!=b[i])
		{
			puts("-1");
			return 0;
		}
	printf("%lld\n",ans);
	return 0;
}