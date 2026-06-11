#include <stdio.h>
#include <string.h>

int main() {
	char a[100];
	int k, length;
	scanf("%d\n%s", &k, &a);
	
	length = strlen(a);
	
	if(length <= k) {
		printf ("%s\n", a);
	}
	else if(length > k ) {
		for ( int i = 0; i < k; i++) {
		printf ("%c", a[i]);
	}
	puts("...");
  }
	
	return 0;
}