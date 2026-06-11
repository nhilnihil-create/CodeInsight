#include <stdio.h>
#include <string.h>

int main()
{
	int A, B;
	char S[11];
	char T[11];
	char U[11];
	
	scanf("%s %s", &S, &T);
	scanf("%d %d", &A, &B);
	scanf("%s", &U);
	
	if (strcmp(S,U) == 0){
		A--;
		printf("%d %d", A,B);
	} else if (strcmp(T,U) == 0){
		B--;
		printf("%d %d", A,B);
	}
		
	return 0;
}
