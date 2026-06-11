#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	int m=n;
	while(m%2==0)m/=2;
	if(m==1)
	{
		puts("No");
		return 0;
	}
	if(n%2==0)m=n-1;else m=n;
	puts("Yes");
	printf("%d %d\n",n+1,n+3);
	for(int i=2;i<=m;i+=2)
		printf("1 %d\n%d %d\n1 %d\n%d %d\n",i,i,i+n+1,i+1,i+n,i+1);
	if(n%2==0)
		for(int i=2;i<n;i++)
			if((n^i^1)<n&&(n^i^1)>1)
			{
				printf("%d %d\n%d %d\n",n,i,n*2,(n^i^1));
				break;
			}
	return 0;
}