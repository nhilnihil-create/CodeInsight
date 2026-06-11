#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int mx=1;
	while(mx<=n)
	{
		mx<<=1;
	}
	mx>>=1;
	if(mx==n)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	printf("1 %d\n",n+2);
	int m=n;
	if(!(n&1))
	{
		m--;
	}
	for(int i=2;i<=m;i++)
	{
		printf("%d %d\n",i,n+1);
		printf("%d %d\n",n+i,i^1);
	}
	if(!(n&1))
	{
		printf("%d %d\n",n,mx);
		printf("%d %d\n",n+n,n^mx^1);
	}
	return 0;
}