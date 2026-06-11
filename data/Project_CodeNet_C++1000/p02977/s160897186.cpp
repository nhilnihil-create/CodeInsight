#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n-(n&(-n))==0)
	{
		cout<<"No";
		return 0;
	}
	puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for(int i=4;i+1+n<=2*n;i+=2)
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",1,i,1,i+1,i,i+1+n,i+1,i+n);
	if(n%2==0)
	{
		for(int i=4;i<n;i++)
			if((n^i^1)!=3&&(n^i^1)<n)
			{
				printf("%d %d\n%d %d\n",n,i,2*n,(n^i^1));
				return 0;
			}
	}
	return 0;
}