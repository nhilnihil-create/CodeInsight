#include<cstdio>
#define max(a,b)(a>b?a:b)
using namespace std;
long long a,b,c,d,ans=-1000000000000000001;
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	ans=max(ans,max(a*c,a*d));
	ans=max(ans,max(b*c,b*d));
	printf("%lld",ans);
	return 0;
}