#include <bits/stdc++.h>
using namespace std;
int n;
inline int lowbit(int x){return(x&(-x));}
int main()
{
	scanf("%d",&n);
	if (n<=2)
	{
		printf("No\n");
		return 0;
	}
	int x=(n>>2);
	if ((x==0 || x-lowbit(x)==0) && n%4==0)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for (int i=1;i<(n+1)/4;i++)
	{
		int a,b,c,d;
		a=i*4,b=a+1,c=a+2,d=a+3;
		printf("%d %d\n",2,b);
		printf("%d %d\n",a,d);
		printf("%d %d\n",d,3);
		printf("%d %d\n",3,a+n);
		printf("%d %d\n",a+n,d+n);
		printf("%d %d\n",c+n,a+n);
		printf("%d %d\n",b+n,a+n);
		printf("%d %d\n",c,n+1);
	}
	if (n%4==0)
	{
		int a,b;
		a=((x-lowbit(x))<<2);
		b=(lowbit(x)<<2);
		b|=1;
		printf("%d %d\n",a+n,n);
		printf("%d %d\n",n+n,b);
	}
	if (n%4==1)
	{
		int a=n-1,b=n;
		printf("%d %d\n",a+n,b);
		printf("%d %d\n",b,1);
		printf("%d %d\n",1,a);
		printf("%d %d\n",a,b+n);
	}
	if (n%4==2)
	{
		int a=n-2,b=n-1,c=n;
		printf("%d %d\n",1,b+n);
		printf("%d %d\n",c+n,a+n);
		printf("%d %d\n",a+n,2);
		printf("%d %d\n",2,c);
		printf("%d %d\n",c,a);
		printf("%d %d\n",c,b);
	}
}