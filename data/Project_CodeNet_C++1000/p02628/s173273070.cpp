#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,k;
int a[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=k;i++)
	ans+=a[i];
	printf("%d\n",ans);
}