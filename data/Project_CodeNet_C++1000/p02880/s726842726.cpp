#include <stdio.h>

int main () {
	int N;
	scanf ("%d", &N);
	for (int i = 1; i < 10; i++) {
		int X = N % i;
		int Y = N / i;
		if (X == 0 && Y < 10) {
			N = N / i;
			printf ("Yes");
			break;
		}
		while (i == 9) {
			printf ("No");
			break;
		}
	}
	
	return 0;
}