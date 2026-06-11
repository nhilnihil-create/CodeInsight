#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int counter = 0;
	for(int i = 0; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			if(i * j == n) {
				counter = 1;
				break;
			}
		}
	}
	
	if(counter == 0) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}