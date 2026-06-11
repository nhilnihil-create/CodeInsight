#include<iostream>
#include<cstdio>
using namespace std;
#define N 200012
int n,m;
int main(){
	scanf("%d",&n);if(!(n&(n-1))){printf("No");return 0;}int i;
	printf("Yes\n");
	printf("%d %d\n",1,2);
	printf("%d %d\n",2,3);
	printf("%d %d\n",3,n+1);
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,n+3);
	for(i=4;i<=n-1;i+=2)
	{
		printf("%d %d\n",i,2);
		printf("%d %d\n",3,i+1);
		printf("%d %d\n",i+1,n+i);
		printf("%d %d\n",i,n+i+1);
	}
	if(!(n&1))
	{
		for(m=n;m&(m-1);m&=(m-1));
		printf("%d %d\n",n,m);m=(n-m)^2;if(m)printf("%d %d\n",n+n,m);else printf("%d %d\n",n+n,2);
	}return 0;
}