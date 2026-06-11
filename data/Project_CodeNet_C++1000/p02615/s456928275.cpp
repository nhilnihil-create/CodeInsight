#include <bits/stdc++.h>
using namespace std;
int n,i,j,a[210000],num;
long long ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	num=n-2;
	for (i=2;i<=n;i++)
	{
		ans+=a[i]*min(2,num);
		num-=2;
		if (num<=0) break;
	}
	printf("%lld",ans);
}