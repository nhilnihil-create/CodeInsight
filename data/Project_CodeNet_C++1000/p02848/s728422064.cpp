#include <stdio.h>

int main () {
	int a ;
	scanf ("%d",&a);
	char n[10000];
	scanf ("%s",n);
	for (int i = 0 ; n[i] != 0 ; i++) {
		if (n[i]+a>'Z') {
			n[i] = n[i] - 26;
		}
		printf("%c",n[i] +a);
	}
	return 0;
}