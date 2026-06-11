#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int n;

void init()
{
	scanf("%d",&n);
}

void work()
{
	if(!(n&n-1))
		puts("No");
	else
	{
		puts("Yes");
		puts("1 2");puts("2 3");
		printf("3 %d\n",n+1);
		printf("%d %d\n",n+1,n+2);
		printf("%d %d\n",n+2,n+3);
		for (int i=4;i<n;i+=2)
			printf("1 %d\n1 %d\n%d %d\n%d %d\n",i,i+1,i,n+i+1,i+1,n+i);
		if(!(n&1))
		{
			for (int i=4;i<=n;i++)
			{
				int j=n^1^i;
				if(j<n&&j!=3)
				{
					printf("%d %d\n%d %d\n",i,n,j,n+n);
					break;
				}
			}
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}