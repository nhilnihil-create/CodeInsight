#include <stdio.h>

int main() {
	long long int test, result = 1;
	scanf("%lld", &test);
	long long x[test];
	
	for(int i = 0; i < test; i++) {
		scanf("%lld", &x[i]);
	}
	for(int i = 0; i < test; i++) {
		if(x[i] == 0) {
			printf("0");
			return 0;
		}
	}
	for(int i = 0; i < test; i++) {
		if(x[i] <= (1000000000000000000 / result)){
			result *= x[i];
		} else {
			result = -1;
			break;
		}
	}
	printf("%lld", result);
	
	return 0;
}