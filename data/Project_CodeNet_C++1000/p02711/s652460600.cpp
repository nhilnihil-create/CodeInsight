#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int firstDigit = N / 100, secondDigit = (N / 10) % 10, thirdDigit = N % 10;
	if (firstDigit == 7 || secondDigit == 7 || thirdDigit == 7) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;	
}