#include <stdio.h>
#include <string.h>

int main() {
	int k;
	char s[105];

	scanf("%d", &k);
	scanf("%s", s);

	if(k < strlen(s)) {
		for(int i = 0; i < k; i++) {
			printf("%c", s[i]);
		}
		puts("...");
	}
	else {
		puts(s);
	}
}