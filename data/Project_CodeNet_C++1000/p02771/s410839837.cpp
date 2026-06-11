#include<stdio.h>
int main()
{
	
	int A;
	int B;
	int C;
	scanf("%d %d %d",&A,&B,&C);
	if(A==B && B==C ||A!=B && B!=C && A!=C)
	{
		printf("No");
	}
	else
	{
		printf("Yes");
	}
	
	return 0;	
}