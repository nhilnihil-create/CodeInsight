#include <stdio.h>
#include <math.h>

int main()
{
	long long  n,k;
	scanf("%lld %lld",&n,&k);
	n=n%k;
	while(abs(n-k)<n)
	{
		n=abs(n-k);
	}
	printf("%lld\n",n);
	
	return 0;
}