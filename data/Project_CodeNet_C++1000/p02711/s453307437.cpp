#include <stdio.h>

int main() {
	int num, num1, num2, num3;
	
	scanf("%d", &num);
	
	num1 = num / 100;
	num2 = (num % 100) / 10;
	num3 = num % 10;
	
	if (num1 == 7 || num2 == 7 || num3 == 7) {
		puts("Yes");
	}
	else {
		puts("No");
	}
	
	return 0;
}