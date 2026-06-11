#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll t1,t2,a1,a2,b1,b2;
	scanf("%lld %lld",&t1,&t2);
	scanf("%lld %lld",&a1,&a2);
	scanf("%lld %lld",&b1,&b2);
	ll a=a1-b1,b=a2-b2;
	if(a<0)
	{
		a=-a,b=-b;
	}
	ll sum=a*t1+b*t2;
	if(sum==0)
	{
		puts("infinity");
		return 0;
	}
	if(sum>0)
	{
		puts("0");
		return 0;
	}
	ll ret=a*t1/(-sum)+(-b)*t2/(-sum);
	if((-b)*t2%(-sum)==0) ret--;
	printf("%lld\n",ret);
	return 0;
}
