#include <stdio.h>

int main(){
	
	
	int A,B;
	char S[15], T[15], U[15];
	
	scanf("%s %s", S, T);
	scanf("%d %d", &A, &B);
	getchar();
	scanf("%s", U);
	if (S[0] == U[0]){
		printf("%d %d", A-1, B);
	}else if (T[0]==U[0]) {
		printf("%d %d", A, B-1);
	}
	


	
	return 0;
}