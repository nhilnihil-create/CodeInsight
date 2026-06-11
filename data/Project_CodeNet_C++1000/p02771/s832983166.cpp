#include<stdio.h>

int main()
{
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);
	
	if(A == B && B != C){
		printf ("Yes\n");
	}
	else if(A != B && A == C){
		printf ("Yes\n");
	}
	else if(B == C && A != C){
		printf ("Yes\n");
	}
	else{
		printf ("No\n");
	}
return 0;
}