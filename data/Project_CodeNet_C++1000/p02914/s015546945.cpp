#include <bits/stdc++.h>
using namespace std;
long long arr[100005],bas[65];
bool b[65];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		for (int j=60;j>=0;j--)
		{
			if (arr[i]&(1LL<<j))
			b[j]^=1;
		}
	}
	long long ans=0;
	for (int i=0;i<=60;i++)
	{
		if (b[i])
		{
			ans+=(1LL<<i);
			for (int j=0;j<n;j++)
			{
				if (arr[j]&(1LL<<i))
				arr[j]^=(1LL<<i);
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=60;j>=0;j--)
		{
			if (arr[i]&(1LL<<j))
			arr[i]^=bas[j];
		}
		for (int j=60;j>=0;j--)
		{
			if (arr[i]&(1LL<<j))
			{
				bas[j]=arr[i];
				break;
			}
		}
	}
	long long mx=0;
	for (int i=60;i>=0;i--)
	{
		if (!(mx&(1LL<<i)))
		mx^=bas[i];
	}
	printf("%lld ",ans+2*mx);
}