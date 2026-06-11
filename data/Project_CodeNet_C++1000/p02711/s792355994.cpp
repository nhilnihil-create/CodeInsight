#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);
	int firstDigit, secondDigit, thirdDigit;
	//987 % 100 = 87
	firstDigit = num / 100;
	secondDigit = (num % 100) / 10;
	thirdDigit = num % 10;
	if (firstDigit == 7 || secondDigit == 7 || thirdDigit == 7) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}