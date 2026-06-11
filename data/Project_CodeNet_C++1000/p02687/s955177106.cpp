#include <stdio.h>
int main() {
	char contest[4];
	
	scanf("%s",&contest);

	if (contest[1] == 'B') {
		printf("ARC\n");
	} else if (contest[1] == 'R') {
		printf("ABC\n");
	}
	return 0;
}