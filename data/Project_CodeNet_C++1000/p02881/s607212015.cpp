#include <cstdio>
#include <cmath>
using namespace std;
long long n;
long long ans;
int main()
{
	scanf("%lld",&n);
	ans=n;
	for (long long i=1;i*i<=n;i++)
		if (n%i==0)
			if (i+n/i-2<ans)
				ans=i+n/i-2;
	printf("%lld\n",ans);
	return 0;
}