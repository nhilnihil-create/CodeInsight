#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	long long n,a,b,m,s,k;
	scanf("%lld %lld %lld",&n,&a,&b);
	m=a+b; s=n%m; k=n/m;
	if(s>a) s=a;
	printf("%lld\n",(k*a)+s);
	return 0;
}