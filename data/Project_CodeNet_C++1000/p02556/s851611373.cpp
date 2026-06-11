#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,a[maxn],b[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[i]=x+y;
		b[i]=x-y;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	printf("%d\n",max(a[n]-a[1],b[n]-b[1]));
	return 0;
}
