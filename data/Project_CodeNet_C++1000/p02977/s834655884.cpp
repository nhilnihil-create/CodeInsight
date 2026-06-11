#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,nn;
int main()
{
	scanf("%d",&n);for(nn=1;nn<n;nn<<=1);
	if(nn==n){puts("No");return 0;}else puts("Yes");
	int a[6]={1,n+2,3,n+1,2,n+3};
	for(int i=1;i<6;i++)printf("%d %d\n",a[i-1],a[i]);
	for(int i=4;i<n;i+=2)
	{
		printf("%d %d\n",i,1);printf("%d %d\n",i,n+i+1);
		printf("%d %d\n",i+1,1);printf("%d %d\n",i+1,n+i);
	}
	if(~n&1)
	{
		for(int i=2;i<n;i++)if((n^i^1)<n)
		{
			printf("%d %d\n",n,i);
			printf("%d %d\n",n+n,n^i^1);
			return 0;
		}
	}
	return 0;
}