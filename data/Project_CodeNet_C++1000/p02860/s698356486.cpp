#include <stdio.h> 

int main () {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	if (n % 2 == 1) {
		printf("No\n");
	} else {
		int flag = 1;
		for (int i = 0; i < n/2 ; i++) {
			if(s[i] != s[i + n /2]) {
				flag = 0;
			}
		}
		if (flag) {
			printf ("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}