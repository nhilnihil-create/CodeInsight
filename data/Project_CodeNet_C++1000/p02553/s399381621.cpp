#include<stdio.h>
#include<algorithm>

using namespace std;
int main()
{
	long long a,b,c,d;
	while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d))
	{
		long long n;
		n=max(a*c,a*d);
		n=max(n,c*b);
		n=max(n,b*d);
		printf("%lld\n",n);
	}
	return 0;
}