#include<iostream>
#include<cstdio>

using namespace std;
const int Mod=1e9+7;
typedef long long LL;
LL n;

LL qsm(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	int i;
	scanf("%lld",&n);
	printf("%lld",((qsm(10ll,n)-qsm(9ll,n)+Mod)-qsm(9ll,n)+Mod+qsm(8ll,n)%Mod)%Mod);
	return 0;
}