#include <stdio.h>
int main ()
{
	int K=1-100,X=1-100000;
	scanf("%d", &K);
	scanf("%d", &X);
	
	if(K*500>=X){
		printf("Yes");
	}else if(K*500<=X){
		printf("No");
	}
	
	return 0;
}