#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	char arr[10000];
	scanf("%s", arr);
	for(int i = 0; arr[i] != '\0'; i++) {
		if(arr[i] + n > 'Z') {
			printf("%c", arr[i] + n - 26);
		}
		else {
			printf("%c", arr[i] + n);
		}
	}
	puts("");
	return 0;
}