#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N=100;
ll a[N];
int main()
{
	ll n,i,j;
	ll num=1000;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;)
	{
		bool sum=0;
		int j;
		if(a[i]>=a[i+1]&&i+1<=n)
		{
			while(a[i]>=a[i+1]&&i+1<=n)
			{
				i=i+1;
			}
			continue;
		}
		for(j=i+1;j<=n;j++)
		{
			if(a[j]>=a[j-1])
			{
				sum=1;
			}
			else break;
		}
		if(sum)
		{
			num=num%a[i]+num/a[i]*a[j-1];
			i=j;
		} 
		else break;
	}
	printf("%lld\n",num);
	return 0;
}