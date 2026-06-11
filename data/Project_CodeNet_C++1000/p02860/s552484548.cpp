#include <stdio.h>

int main() {
	int x, j, count = 0;
	scanf("%d", &x);
	j = x / 2;
	char str[x], half1[j] = {}, half2[j] = {};
	scanf("%s", str);
	
	if(x % 2 != 0) {
		printf("No");
		return 0;
	}
	int sh = j;
	for(int i = 0; i < j; i++) {
		half1[i] = str[i];
		half2[i] = str[sh];
		sh++;
	}
	for(int i = 0; i < j; i++) {
		if(half1[i] == half2[i]) {
			count++;
		} else {
			printf("No");
			break;
		}
	}
	if(count == j) {
		printf("Yes");
	}
	
	return 0;
}