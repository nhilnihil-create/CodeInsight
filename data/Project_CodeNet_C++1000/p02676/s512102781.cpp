#include <stdio.h>

int main () {
	int k, length = 0;
	char string[100];
	scanf("%d", &k);
	scanf("%s", string);

	for (int i = 0; string[i] != '\0'; i++) {
		length++;
	}
	
	if (length <= k) {
		printf("%s", string);
	}
	else {
		for (int i = 0; i < k; i++) {
			printf("%c", string[i]);
		}
		printf("...");
	}
	
	
	return 0;
}