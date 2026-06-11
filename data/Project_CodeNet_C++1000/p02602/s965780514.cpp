#include <stdio.h>

int main() {
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	int c[200000];
	
	for(int i = 0; i < a; i++) {
		
		scanf("%d", &c[i]);
	}


	for(int i = b; i < a; i++) {
		if(c[i] > c[i - b]) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}
