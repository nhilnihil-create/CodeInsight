#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char s[105];

	scanf("%d", &n);
	scanf("%s", s);

	int flag = 1;

	if(n % 2 == 1) {
		puts("No");
	}
	else {
		for(int i = 0; i < n / 2; i++) {
			if(s[i] != s[i + n / 2]) flag = 0;
		}

		if(flag) puts("Yes");
		else puts("No");
	}
}