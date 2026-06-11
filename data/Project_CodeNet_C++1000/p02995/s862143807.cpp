#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;

int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long k=c*d/(__gcd(c,d)); 
	long long ans=(b-a)+1-(b/c-(a-1)/c)-(b/d-(a-1)/d)+ (b/k-(a-1)/k);
	printf("%lld\n",ans);
	return 0;
}