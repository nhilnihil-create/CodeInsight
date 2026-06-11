#include <stdio.h>

int main() {
	int a1, a2, a3;
	int sum;
	scanf("%d %d %d", &a1, &a2, &a3);

	sum = a1 + a2 + a3;
	if (sum < 22){
		printf("win\n");
	}else{
		printf("bust\n");
	}
	
	return 0;
}