#include<stdio.h>
int main()
{
	int N,K,R,hasil;
		scanf("%d",&N);
			getchar();	
	scanf("%d",&R);
			getchar();
	
	if(N <=10)
	{
	hasil =	100 * (10-N);
	K = R + hasil;	
		
	}
	else
	{
	K = R;
	
	}
	printf("%d",K);
	
	
	return 0;
}