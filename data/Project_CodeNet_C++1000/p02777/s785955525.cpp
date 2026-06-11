#include <stdio.h>
#include <string.h>
int main ()
{
	char S[20],T[20],U[20];
	int A,B;
	scanf("%s %s\n%d %d\n%s", S,T,&A,&B,U);
	if((strcmp(S,U)) == 0) {
		printf("%d %d\n", A-1,B);
	}
	else if((strcmp (T,U))== 0) {
		printf("%d %d\n", A,B-1);
	}
}