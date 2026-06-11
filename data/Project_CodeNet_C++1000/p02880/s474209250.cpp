#include <stdio.h>

int main () {
	int num, ctr, temp;
	scanf("%d", &num);
	for(int i = 1; i <= 9; i++) {
		if(num % i == 0) {
			temp = i;
			for(int j = 1; j <= 9; j++) {
				if(temp*j == num) {
					ctr++;
				}
			}
		}
	}
	if(ctr > 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
			
	
	return 0;
}