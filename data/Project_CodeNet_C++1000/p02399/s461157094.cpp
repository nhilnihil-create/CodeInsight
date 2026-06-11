#include <stdio.h>

int main(){
	
	int a,b;
	
	scanf("%d", &a);		
	scanf("%d", &b);

	printf("%d ",a/b);
	printf("%d ",a%b);
	printf("%.8f\n",(double)a/b);
	return 0;
}