#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
using namespace std;
const int N=1e5+100;
int n,m,v,p,a[N],sum[N],ans;
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	a[n+1]=inf;
	for (int i=n;i>=1;i--)
	{
		if (i>=v)
		{
			int pos=upper_bound(a+1,a+2+n,a[i]+m)-a;
			if (n-pos+1<p) ans++;
		}
		else
		{
			int pos=upper_bound(a+1,a+2+n,a[i]+m)-a;
			if (n-pos+1>=p) continue;
			if (v-i-p+1<=0)
			{
				ans++;
				continue;
			}
			int cnt=v-i-p+1;
			int l=i+1,r=min(n-p+1,pos-1);
			if (r-l+1>=cnt && cnt*m<=(a[i]+m)*(r-l+1)-(sum[r]-sum[l-1])) ans++;
		}
	}
	printf("%lld\n",ans);
}