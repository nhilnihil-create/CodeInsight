#include <stdio.h>

int main() {
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);

	int ctr = 0;
	int sum = 0;
	
	while (c > sum) {
		if(b >= a) {
			sum += b;
			ctr++;
		}
		else {
			sum += + a;
			ctr++;
		}
	}
	printf("%d\n", ctr);
	return 0;
}

