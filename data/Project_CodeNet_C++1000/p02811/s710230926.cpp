#include<stdio.h>

int main()
{
	int K;
	int X;
	scanf("%d %d",&K,&X);
	K = K*500;
	if(K>=X){
		printf("Yes");
	}
	if(K<X){
		printf("No");
	}
	
	return 0;	
}
	