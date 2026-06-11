#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int sum=0;
	while(a>=b)
	{
		b*=2;
		sum++;
	}
	while(c<=b)
	{
		sum++;
		c*=2;
	}
	if(sum<=d) 
	printf("Yes");
	else
	printf("No");
	return 0;
}