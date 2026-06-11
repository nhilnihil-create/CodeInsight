#include<stdio.h>
int main()
{
	int N,R,K,H;
	scanf("%d %d",&N,&R);
	if(N<10)
	{
		K=100*(10-N);
		H=K+R;
		printf("%d",H);
	}
	else
	{
		printf("%d",R);
	}
}