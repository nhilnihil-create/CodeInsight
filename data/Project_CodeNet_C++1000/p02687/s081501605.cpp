#include <stdio.h>
int main() {
	char A [5];
	scanf("%s", A);
	
	if(A [1] == 'B') {
		A [1] = 'R';
		printf("%s", A);
	}
	else if(A [1] == 'R') {
		A [1] = 'B';
		printf("%s", A);
	}
	return 0;
}