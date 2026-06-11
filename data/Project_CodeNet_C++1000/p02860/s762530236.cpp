#include <stdio.h>
#include <string.h>

int main () {
	int n;
	char s[105];
	
	scanf("%d", &n);
	scanf("%s", s);
	
	if(n % 2 != 0) {
		printf("No\n");
	}
	else {
		int mid = n/2;
		int i = 0;
		while (s[i] == s[mid + i]) {
			i += 1;
		}

		if(i == mid) {
			printf("Yes\n");
		}
		else if(i < mid) {
			printf("No\n");
		}
	}
	
	return 0;
}