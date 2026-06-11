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
int main()
{
	LL co=2;
	LL n;scanf("%lld",&n);
	for(LL k=2;k<=n/k;++k)
	{
		LL now=n;
		while(now>=k&&now%k==0)now/=k;
		if(now%k==1)co++;
		if(n%k==1&&k*k!=n-1)co++;
	}
	if(n==2)co=1;
	printf("%lld\n",co);
}