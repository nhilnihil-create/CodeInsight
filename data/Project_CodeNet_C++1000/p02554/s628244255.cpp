#include<iostream>
#include<cstdio>
using namespace std;
int mod=1000000007;
int main()
{
	long long n;
	scanf("%lld",&n);
	long long ans=1%mod;
	long long sum=1%mod;
	long long tot=1%mod;
	for(int i=1;i<=n;i++)
	{
		ans=ans*10%mod;
	}
	for(int i=1;i<=n;i++)
	{
		sum=sum*9%mod;
	}
	for(int i=1;i<=n;i++)
	{
		tot=tot*8%mod;
	}
	printf("%lld",(ans+mod-(sum*2%mod-tot)%mod)%mod);
	return 0;
}