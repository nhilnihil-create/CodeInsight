#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
	scanf("%d",&b[i]);
	int l=n-1;
	long long ans=0;
	for (int i=0;;i=(i+1)%n)
	{
		bool ch=0;
		int x=b[(i-1+n)%n],y=b[i],z=b[(i+1)%n];
		if (y>x+z && y!=a[i])
		{
			b[i]%=(x+z);
			if (b[i]<a[i])
			{
				if ((a[i]-b[i])%(x+z))
				{
					printf("-1");
					return 0;
				}
				b[i]=a[i];
			}
			ans+=(y-b[i])/(x+z);
			l=i;
			ch=1;
		}
		if (l==i && !ch)
		break;
	}
	for (int i=0;i<n;i++)
	{
		if (a[i]!=b[i])
		{
			printf("-1");
			return 0;
		}
	}
	printf("%lld",ans);
}