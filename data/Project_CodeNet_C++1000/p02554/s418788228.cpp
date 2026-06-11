#include<cstdio>
#define LL long long
#define mod 1000000007
using namespace std;
LL qmi(LL a,LL b)
{
	LL res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	LL n;scanf("%lld",&n);
	printf("%lld",((qmi(10ll,n)-2*qmi(9ll,n)+qmi(8ll,n))%mod+mod)%mod);
	return 0;
}