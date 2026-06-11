#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;scanf("%d",&n);
	int s=1;
	while(s<n)s<<=1;
	if(s==n){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<=2;i++)
		printf("%d %d\n",i,i+1);
	printf("3 %d\n",n+1);
	for(int i=1;i<=2;i++)
		printf("%d %d\n",n+i,n+i+1);
	for(int i=4;i<n;i+=2)
	{
		printf("1 %d\n",i);
		printf("1 %d\n",i+1);
		printf("%d %d\n",i,i+n+1);
		printf("%d %d\n",i+1,i+n);
	}
	if(n%2==0){
		for(int i=2;i<n;i++)
		{
			if(i==3)continue;
			int x=n^i^1;
			if(x>=n||x==3)continue;
			printf("%d %d\n",n,x);
			printf("%d %d\n",n*2,i);
			break;
		}
	}
	return 0;
}