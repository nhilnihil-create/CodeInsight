#include<bits/stdc++.h>
using namespace std;
long long int a[1000100];
long long int b[1000100];
int main()
{
	long long int n,i,ans = 0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=1e18;
	}
	b[0]=1;
	if(b[0]<a[0])
	{
		printf("-1");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		b[i+1]= (b[i]-a[i])*2;
		if(b[i]<0)
		{
			printf("-1");
			return 0;
		}
		if(b[i]>=1e18) break;
	}
	if(a[n]>b[n])
	{
		printf("-1");
		return 0;
	}
	long long int now;
	b[n]=ans=now=a[n];

	for(i=n-1;i>=0;i--)
	{
		now=min(now,b[i]-a[i])+a[i];
		ans+=now;
	}
	printf("%lld\n",ans);
}