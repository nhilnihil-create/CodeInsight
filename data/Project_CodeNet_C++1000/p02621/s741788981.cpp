#include <stdio.h>
#include <string.h>

int main(){
	int a;
	scanf("%d", &a);
	
	int sum = 0;
	sum = a + a * a + a * a * a;
	printf("%d", sum);
	
	
	return 0;
}