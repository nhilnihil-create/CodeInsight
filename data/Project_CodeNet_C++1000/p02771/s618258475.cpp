#include<stdio.h>

int main(){
 	int A, B, C;
 	scanf("%d %d %d", &A, &B, &C);
	if(A == B){
		if(A != C){
			printf("Yes");
		}
		else{
			printf("No");
		}
	}
	else if(A == C){
		if(A != B){
			printf("Yes");
		}
		else{
			printf("No");
		}
	}
	else if (B == C){
		if(B != A){
			printf("Yes");
		}
		else{
			printf("No");
		}
	}
	else{
		printf("No");
	}
	return 0;
 }