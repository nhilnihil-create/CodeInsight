#include <stdio.h>

int main() {
	int n, ctr = 0;
	scanf("%d", &n);
	char s[n+1];
	scanf("%s", s);
	
	for (int i = 0, j = n/2; i < n/2; i++, j++){
		if (s[i] == s[j]) {
			ctr++;
		}
	}
	if (n % 2 != 0 || ctr != n/2) {
		printf("No\n");
	}
	else if (ctr == n/2) {
		printf("Yes\n");
	}
	
	return 0;
}