#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[2001];
long long mod=1e9+7;
int main()
{
	long long n;
	scanf("%lld",&n);
	a[1]=0,a[2]=0,a[3]=1;
	for(long long i=4;i<=n;i++)
	{
		a[i]=(a[i-1]+a[i-3])%mod;
	}
	printf("%lld",a[n]);
	return 0;
}