#include<bits/stdc++.h>
#define maxn 150005
#define eps 1e-10
#define mp(x,y) make_pair(x,y)
#define se second
#define fi first
#define inf 50000000
using namespace std;
typedef long long int ll;
int n,m,v,p;
int a[100005];
ll sum[100005];
ll piao=0;
int main()
{
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		piao=(ll)m*v;
		int A=a[i]+m;
		int t2=upper_bound(a+1,a+n+1,A)-a-1;
		int t1=upper_bound(a+1,a+n+1,A-m)-a;
		
		cnt=n-t2;

		piao-=(ll)cnt*m+(ll)(t1-1)*m;
		if(piao<=0)
		{
			ans+=(cnt<p);
			continue;
		}
		
		
			int l=t1-1,r=t2,cnt2=l;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if((ll)A*(mid-t1+1)-(sum[mid]-sum[t1-1])+(ll)(t2-mid)*m<piao)
				{
					r=mid-1;
				}
				else cnt2=mid,l=mid+1;
			}
			cnt+=(t2-cnt2);
		
		if(cnt<p)ans++;
	}
	printf("%d\n",ans);
}