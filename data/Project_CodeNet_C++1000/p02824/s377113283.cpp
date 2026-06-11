#include <algorithm>
#include <cstdio>
#define N 100005
using namespace std;
typedef long long ll;
ll n,m,v,p,a[N],ans,sum[N];
int main() 
{
    scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
    for(ll i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}ans=p;sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n-p;i++){
		ll tmp=m*v-m*p;
		if(a[i]+m<a[n-p+1])continue;
		if(tmp<=(i-1)*m+(n-p-i+1)*(a[i]+m)-(sum[n-p+1]-sum[i]))ans++;
	}printf("%lld",ans);
	return 0;
}
