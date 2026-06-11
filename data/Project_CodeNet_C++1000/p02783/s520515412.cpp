#include<stdio.h>

int main()
{
	int H;
	int A;
	int X;
	scanf("%d %d",&H,&A);
	X= H / A;
	//printf("%d",X);
	if(H % A == 0 )
	{
		printf("%d",X);
	}
	else
	{
		printf("%d",X+1);
	}
	
	return 0;	
}
	