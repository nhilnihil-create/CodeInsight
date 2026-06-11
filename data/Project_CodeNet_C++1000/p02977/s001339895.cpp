#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int read()
{
	char c=getchar();
	int res=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=getchar();
	return res;
}
int tot=0;
struct Edge
{
	int x,y;
}e[200005];
int n;
int main()
{
	n=read();
	if(!(n&(n-1))) return puts("No"),0;
	puts("Yes");
	printf("%d %d\n",1,2);
	printf("%d %d\n",2,3);
	printf("%d %d\n",3,n+1);
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,n+3);
	for(int i=4;i<n;i+=2)
	{
		int j=i^1;
		printf("%d %d\n",1,i);
		printf("%d %d\n",1,j);
		printf("%d %d\n",i,j+n);
		printf("%d %d\n",j,i+n);
	}
	if(!(n&1))
	{
		for(int i=4;i<=n;i++)
		{
			int j=n^i^1;
			if(j!=3&&j<n)
			{
				printf("%d %d\n",i,n);
				printf("%d %d\n",j,2*n);
				return 0;
			}
		}
	}
}