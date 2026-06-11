#include <stdio.h>

int main(){
	int a,b,c;
	scanf("%d %d %d", &a,&b, &c);
	
	int sum;
	sum = ((b/c*c-(a+c-1)/c*c)/c+1);
	
	printf("%d", sum);
	
	return 0;
}