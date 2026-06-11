#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int M=505;
int a[M];
int n,k;

int rm[M];

bool check(int d)
{
	for(int i=0;i<n;i++)
		rm[i]=a[i]%d;
	sort(rm,rm+n);
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=rm[i];
	int pre=0;
	for(int i=0;i<n;i++)
	{
		pre+=rm[i];
		if(pre==((LL)n-i-1)*d-(sum-pre)) break;
	}
	return pre<=k;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	int ans=0;
	for(int i=1;i<=sum/i;i++)
	{
		if(sum%i) continue;
		if(check(sum/i))
		{
			ans=sum/i;
			break;
		}
		if(check(i))
			ans=i;
	}
	printf("%d\n",ans);
	return 0;
}