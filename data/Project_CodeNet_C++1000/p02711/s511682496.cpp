#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	
	int firstDigit = n / 100;
	int secondDigit = (n / 10) % 10;
	int thirdDigit = n % 10;
	
	while ( n > 0) {
		if ( firstDigit == 7) {
			puts("Yes");
			break;
		}
		else if ( secondDigit == 7) {
			puts("Yes");
			break;
		}
		else if ( thirdDigit == 7) {
			puts("Yes");
			break;
		}
		else {
			puts("No");
			break;
		}
	} 
	return 0;
}