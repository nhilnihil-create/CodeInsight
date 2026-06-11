#include <stdio.h>
#include <string.h>

int main() {
	int a;
	char b[a];
	
	scanf("%d", &a);
	scanf("%s", b);
	
	int c = 0;
	
	if(a < 2) {
		printf("No\n");
		return 0;
	}
	
	if(a%2 != 0) {
		printf("No\n");
		return 0;
	}
	
	for(int i = 0; i < a/2; i++) {
		
		if(b[i] == b[i + (a / 2)]) {
			continue;
		}
		
		else if (b[i] != b[i + (a/2)]) {
			c++;
		}
		i++;
	}
	
	if(c != 0) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}

	return 0;
}
