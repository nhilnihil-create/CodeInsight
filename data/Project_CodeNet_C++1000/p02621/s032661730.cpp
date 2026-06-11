#include <stdio.h>

int main(){
	
	int a;
	int powerOne, powerTwo, powerThree, total;
	
	scanf("%d", &a);
	
	powerOne = a;
	powerTwo = a * a;
	powerThree = a * a * a;
	total = powerOne + powerTwo + powerThree;
	
	printf("%d", total);
	
	return 0;
	
}