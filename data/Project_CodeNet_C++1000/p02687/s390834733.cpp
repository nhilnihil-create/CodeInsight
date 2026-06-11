#include <stdio.h>

int main() {
	char a[4];
	
	scanf("%s", &a);
	
	if (a[1] == 'R') {
		a[1] = 'B';
		printf("%s\n", a);
		return 0;
	}
	if(a[1] == 'B') {
		a[1] = 'R';
		printf("%s\n", a);
	}
	return 0;
}