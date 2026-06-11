#include <stdio.h>

int main() {
	int N; 
	long long int sum = 0;
	scanf("%d", &N);
	
	for (int i = 0; i <= N; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			continue;
		} 
		else if (i % 3 == 0 || i % 5 == 0) {
			continue;
		} 
		else {
			sum += i;
		}
	}
	printf("%lld\n", sum);
	
	return 0;
}