#include <stdio.h>

int main () {
	long long int a, sum = 0;
	scanf ("%lld", &a);
	for (long long int i = 1; i <= a; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
		} else sum += i;
	}	
	printf ("%lld", sum);
	return 0;
}