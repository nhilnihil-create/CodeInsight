#include <stdio.h>

int main() {
	char a[10];
	char b[10] = "ABC";
	char c[10] = "ARC";
	
	scanf("%s", a);
	
	if(a[1] == 66) {
		printf("%s", c);
	} else {
		printf("%s", b);
	}
	
	
	return 0;
}