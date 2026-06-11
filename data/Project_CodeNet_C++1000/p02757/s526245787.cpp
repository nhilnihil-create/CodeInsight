#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll a[maxn], num[maxn];//a records the number string, num[i] records the number of number string who modules p has remainder i
int qpow(int a, int b, int p)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans = (ans*a) % p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
int main()
{
	ll n,p;
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[i]);
	}
	ll ans=0;
	if(p==2 || p==5)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]%p == 0) ans+=i;
		}
	}
	else
	{
		num[0]=1;//0 % p = 0, so initialize 1
		ll sum=0, x=1;//sum is the number corresponding to number string, x is 1ex
//		for(int i=n;i>=1;i--)
//		{
//			(sum+=a[i]*x)%=p;//sum=sum+s[i]*x, sum=sum%p;
//			x=x*10%p;
//			ans+=num[sum]++;
//		}
		for(int i=1;i<=n;i++)
		{
			sum=(sum*10+a[i]) % p;
			ans += num[( sum * qpow(x, p-2, p) )% p]++;
			x=x*10%p;
		}
	}
	cout<<ans<<endl;
}