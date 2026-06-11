#include <stdio.h>

int main ()
{
	int A, B, C;
	
	scanf("%d %d %d", &A, &B, &C);
	
	if (A==B && A!=C && B!=C){
		printf("Yes");
	} else if (A==C && A!=B && B!=C){
		printf("Yes");
	}else if (B==C && A!=B && A!=C){
		printf("Yes");
	}else if (A==B && A==C && B==C){
		printf("No");
	}else if (A!=B && A!=C && B!=C){
		printf("No");
	}
		
	return 0;
}