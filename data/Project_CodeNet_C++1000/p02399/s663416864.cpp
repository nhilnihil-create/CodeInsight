#include<stdio.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d %d ", a / b, a%b);
	printf("%f", a*1.0 / b*1.0);

	return 0;
}