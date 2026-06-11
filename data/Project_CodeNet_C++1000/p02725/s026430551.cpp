#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=2000100;
int k,n;
int a[maxn];
int ans=0;
int main()
{
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		ans=max(ans,a[i]-a[i-1]);
		//printf("%d\n",ans);
	}
	ans=max(ans,k-a[n]+a[1]);
	printf("%d\n",k-ans);
	return 0;
}
