#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);
	int sum = 0;
	sum = num + num*num + num*num*num;
	printf("%d", sum);
}