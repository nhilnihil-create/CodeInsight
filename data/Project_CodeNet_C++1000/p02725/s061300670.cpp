#include <bits/stdc++.h>
using namespace std;
int a[210000],i,j,n,m,k,maxn;
int main()
{
	scanf("%d%d",&k,&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]-a[i-1]);
	}
	maxn=max(maxn,k-(a[n]-a[1]));
	printf("%d",k-maxn);
}