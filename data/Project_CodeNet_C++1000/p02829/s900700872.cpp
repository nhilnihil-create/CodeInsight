#include<stdio.h>

int main()
{
	int A;
	int B;
	scanf("%d %d",&A,&B);
	if(A == 1 && B == 2)
	{
		printf("3");
	}
		if(A == 2 && B == 1)
	{
		printf("3");
	}
	if(A == 1 && B == 3)
	{
		printf("2");
	}
		if(A == 3 && B == 1)
	{
		printf("2");
	}
	if(A == 2 && B == 3)
	{
		printf("1");
	}
		if(A == 3 && B == 2)
	{
		printf("1");
	}
	return 0;	
}
	