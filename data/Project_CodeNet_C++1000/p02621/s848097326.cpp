#include<stdio.h>

int main(){
	int total,a;
	scanf("%d", &a);
	total = a + (a*a) + (a * a * a);
	
	printf("%d", total);
	
	return 0;	
}