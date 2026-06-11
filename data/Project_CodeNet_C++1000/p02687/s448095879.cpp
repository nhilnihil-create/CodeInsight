#include <stdio.h>

int main() {
	char U[4];
	scanf("%s", &U);
	switch (U[1]) {
		case 'B':
			printf("ARC");
			break;
		case 'R':
			printf("ABC");	
	}
	return 0;
}