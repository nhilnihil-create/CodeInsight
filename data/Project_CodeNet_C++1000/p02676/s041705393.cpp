#include <stdio.h>
#include <string.h>

int main() {
	int k;
	char str[101];
	scanf("%d %s", &k, str);
	int len = strlen(str);
	if (len <= k) {
		printf("%s\n", str);
	}
	else {
		for (int i = 0; i < k; i++) {
			printf("%c", str[i]);
		}
		puts("...");
	}
	return 0;
}