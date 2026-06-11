#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 200005
int a[maxn];
using namespace std;
int main(void)
{
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		sum^=a[i];
	}
	for(int i=0;i<n-1;++i)
	{
		printf("%d ",sum^a[i]);
	}
	printf("%d\n",sum^a[n-1]);
	
	return 0;
}