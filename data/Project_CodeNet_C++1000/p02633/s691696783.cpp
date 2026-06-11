#include<cstdio>
int n,m,r;
int main()
{
	scanf("%d",&n),m=360;
	for(;m;r=n%m,n=m,m=r);
	return printf("%d",360/n),0;
}