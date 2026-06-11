#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n==1) puts("No");
	else if(n&1)
	{
		puts("Yes");
		for(int i=2;i<=n;i+=2)
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",n+i,i+1,i+1,1,1,i,i,n+i+1);
		printf("%d %d\n",n+2,n+1);
	}
	else 
	{
		for(int j=2;j<n;j++)
		if((n^j^1)<n)
		{
			puts("Yes");
			for(int i=2;i<n;i+=2)
			printf("%d %d\n%d %d\n%d %d\n%d %d\n",n+i,i+1,i+1,1,1,i,i,n+i+1);
			printf("%d %d\n%d %d\n",n,j,n+n,n^j^1);
			printf("%d %d\n",n+2,n+1);
			return 0;
		}
		puts("No");
	}
	return 0;
}
		