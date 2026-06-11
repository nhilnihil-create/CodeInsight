#include<stdio.h>
int main(void){
	int A, L, I[1000];
	scanf("%d", &A);
	for (L = 0; L < A; L++){
		scanf("%d", &I[L]);
	}
	for (L = A-1; L >= 0; L--){
		printf("%d", I[L]);
		if (L != 0){
			printf(" ");
		}
	}
        printf("\n");
	return 0;
}