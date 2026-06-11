#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	long long int n,a,b,x=0,y=0;
	scanf("%lld %lld %lld",&n,&a,&b);
	x=n/(a+b)*a;
	y=n%(a+b);
	if(y>a)	y=a;
	printf("%lld\n",x+y);
	return 0;
}
