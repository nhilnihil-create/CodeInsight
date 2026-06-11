#include <stdio.h>

int main() {
	int a, b;
	int k;
	
	scanf("%d", &k);
	scanf("%d %d", &a, &b);
	
		
	for (int i = a; i <= b; i++) {	
		
		int c;
		c = a%k;
		
		if(c != 0 && a <= b) {
			a++;
			continue;
		}
		if(c == 0 && a <= b) {
			printf("OK\n");
			return 0;
			
		}
	}
	printf("NG\n");
	return 0;
}