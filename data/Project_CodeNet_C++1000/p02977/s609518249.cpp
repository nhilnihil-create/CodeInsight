#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n-(n&-n)==0){printf("No");return 0;}
	printf("Yes\n");
		
	if(n==3)
	{
		printf("1 2\n2 3\n3 4\n4 5\n5 6\n");
		return 0;
	}
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for(int i=4;i+1<=n;i+=2)
	{
		printf("%d %d\n%d %d\n",n+1,i,i,i+n+1);
		printf("%d %d\n%d %d\n",n+1,i+1,i+1,i+n);
	}
	if(n%2==0)
	{
		int k=n&-n;
		int x=n^k^1;
		if(k!=2)
			printf("%d %d\n%d %d\n",k,n,x,n+n);
		else
			printf("%d %d\n%d %d\n",n+2,n,x,n+n);
	}
	return 0;
}
