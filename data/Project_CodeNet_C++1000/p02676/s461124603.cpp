#include <stdio.h>
#include <string.h>

int main () {
	int k;
	char s[101];
	scanf ("%d", &k);
	scanf ("%s", &s);
	int pnjg = strlen(s);
	if (pnjg<=k) {
		printf ("%s", s);
	} else {
		s[k] = '\0';
		printf ("%s...", s);
		
	}
	return 0;
}