#include <stdio.h>
int main(void){
	int a, b = 0;
	scanf("%d%d", &a, &b);
	printf("%d %d %.5f", (a/b), (a%b), (1.0*a/b));
}