#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if (!(n&(n-1))) return puts("No"),0;
	puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for (int i=4;i<n;i+=2) printf("1 %d\n%d %d\n1 %d\n%d %d\n",i,i,i+1+n,i+1,i+1,i+n);
	if (!(n&1))
	{
		for (int i=2;i<=n;i++)
		{
			int j=i^n^1;
			if (i!=3&&j!=3&&j<=n)
			{
				printf("%d %d\n%d %d\n",i,n,j,2*n);
				break;
			}
		}
	}
	return 0;
}