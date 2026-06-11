#include<stdio.h>
int main()
{
	int N;
	int X;
	scanf("%d",&N);
	X= N/2;
	if(N%2==0)
	{
		printf("%d",X);
	}
	else if(N%2!=0)
	{
		printf("%d",++X);
	}
	

	
	return 0;
}