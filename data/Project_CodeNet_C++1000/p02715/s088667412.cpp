#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<functional>
using namespace std;
typedef long long LL;
inline LL read()
{
	LL kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
const LL mod=1e9+7;
LL cun[2000222];
LL qp(LL a,LL b)
{
	LL kk=1;
	while(b)
	{
		if(b&1)kk=(kk*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return kk;
}
LL n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	LL asd=0;
	for(LL i=k;i>=1;--i)
	{
		cun[i]=qp(k/i,n);
		for(LL j=2;j<=k/i;++j)
		{
			cun[i]-=cun[i*j];
		}
		asd=(asd+(i*cun[i]%mod)+mod)%mod;
	}
	printf("%lld\n",(asd+mod)%mod);
}