#include <stdio.h>

int main() {
	long long int a;
	
	scanf("%lld", &a);
	
	long long int tot = 0;
	
	for(int i = 1; i <= a; i++) {
		if(i%3 == 0) {
			tot += 0;
		}
		else if(i%5 == 0) {
			tot += 0;
		}
		else{
			tot += i;
		}
	}
	
	printf("%lld\n", tot);
	
	return 0;
}
