#include <stdio.h>

int main(){
	char S [5];
	scanf("%s", &S);
	switch (S[1]) {
		case 'R':
			printf("ABC\n", S);
			break;
		case 'B':
			printf("ARC\n", S);
			break;
	}
	
	return 0;
}

