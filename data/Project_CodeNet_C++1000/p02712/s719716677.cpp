#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
long long sum=0,n,i;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		if((i%3)==0)
			continue;
		else if((i%5)==0)
			continue;
		else
			sum+=i;
	}
	printf("%lld\n",sum);
	return 0;
}