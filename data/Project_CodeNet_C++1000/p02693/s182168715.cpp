#include <stdio.h>

int main () {
	
	int K, A, B;
	scanf("%d %d %d", &K, &A, &B);
	
	int x;
	
	for (A; A <= B; A++){
		if(A % K == 0){
		x++;}
	}
	if(x != 0 ){
		printf("OK ");
	} else{
		printf("NG ");
	}
	
	return 0;
}