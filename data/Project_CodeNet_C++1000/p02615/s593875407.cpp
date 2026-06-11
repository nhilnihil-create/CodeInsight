#include<bits/stdc++.h>
using namespace std;

int n,now;
int a[200010];
long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans=a[n];
	now=3;
	for(int i=n-1;i;i--)
	{
		if(now>n) break;
		ans+=a[i];
		now++;
		if(now>n) break;
		ans+=a[i];
		now++;
	}
	printf("%lld\n",ans);
	return 0;
}