#include <stdio.h>


int main () {
	long long int N;
	scanf("%lld", &N);
	char nama[100];
	int i = 0;
	
	while ( N != 0) {
		N--;
		int M = N % 26;
		nama[i] = 'a' + M;
		N /= 26;
		i++;
	}
	
	for (int j = i - 1 ; j >= 0 ; j--) {
		printf("%c", nama[j]);
	}
	
	return 0;
}