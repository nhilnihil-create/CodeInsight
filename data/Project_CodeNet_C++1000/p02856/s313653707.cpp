#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,i,u,v,ans=0,sum=0;
int main()
{
	scanf("%lld",&n);
	ans=-1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&u,&v);
		sum+=u*v;
		ans+=v;
	}
	ans+=(sum-1)/9;
	printf("%lld\n",ans);
	return 0;	
} 