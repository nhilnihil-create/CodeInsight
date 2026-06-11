#include<cstdio>
typedef long long ll;
ll abs(ll a,ll b)
{
	if(a>b)return a-b;
	return b-a;
}
int main()
{
	ll n,k;
	while(~scanf("%lld %lld",&n,&k))
	{
		n=n%k;
		while(n>=abs(n,k))
		{
			n=abs(n,k);
		}
		printf("%lld\n",n);
	}
	return 0;
} 