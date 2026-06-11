#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define ufor(i,l,r) for (int i=l;i<=r;i++)
#define MAXN 1000500
int a[MAXN];
int main()
{
	int n,k;
	scanf("%d%d",&k,&n);
	int ans=0;
	ufor (i,1,n)
	{
		scanf("%d",&a[i]);
		ans=max(ans,a[i]-a[i-1]);
	}
	ans=max(ans,k-a[n]+a[1]);
	printf("%d",k-ans);		
	return 0;
}
