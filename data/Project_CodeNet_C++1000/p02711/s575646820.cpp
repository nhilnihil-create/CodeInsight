#include <stdio.h>
int main() {
	int N;
	scanf ("%d", &N);
	
	int firstdigit = N / 100;
	int seconddigit = (N % 100) / 10;
	int thirddigit = N % 10;
	
	if (firstdigit == 7 || seconddigit == 7 || thirddigit == 7){
		printf ("Yes");
	}
	else {
		printf ("No");
	}
	return 0;
}