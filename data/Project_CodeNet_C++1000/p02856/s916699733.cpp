#include<iostream>
#include<cstdio>
using namespace std;
int main ()
{
	int m,i;
	scanf("%d",&m);
	long long sum=0,num=0;
	for(i=1;i<=m;++i)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		sum+=a*b;
		num+=b;
	}
	num--;
	num+=(sum-1)/9;
	printf("%lld\n",num);
}