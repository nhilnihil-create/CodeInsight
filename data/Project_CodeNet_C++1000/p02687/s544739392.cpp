#include <stdio.h>

int main() {
	char S[5];
	scanf("%s", &S);
	
	if(S[1] == 'B') {
		printf("ARC\n");
	} else {
		printf("ABC");
	}
	return 0;
}