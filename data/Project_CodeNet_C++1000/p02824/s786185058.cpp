#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,v,p;
int a[100005],ans,nums=0;
long long sum[100005];
int main()
{
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		if(a[i]==a[i-1]) nums++;
		else nums=1;
		if(i-nums+1<=p)
		{
			ans++;
			continue;
		}
		if(a[i]+m<a[p]) break;
		int num=p-1+(n-i)+nums-1;
		if(num>=v-1) ans++;
		else
		{
			int l=p,r=i-nums;
			if(l>r) break;
			else
			{
				while(l<r)
				{
					int mid=(l+r)>>1;
					if(a[i]+m>=a[mid]) r=mid;
					else l=mid+1;
				}
				if(1ll*(a[i]+m)*(i-nums-l+1)-(sum[i-nums]-sum[l-1])>=1ll*(v-num-1)*m) ans++;
				else break;
			}
		}
	}
	printf("%d\n",ans);
}