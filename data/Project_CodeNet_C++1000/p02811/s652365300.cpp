#include<stdio.h>
int main()
{
	int K;
	int X;
	scanf("%d  %d",&K,&X);
	if(X<=K*500){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}