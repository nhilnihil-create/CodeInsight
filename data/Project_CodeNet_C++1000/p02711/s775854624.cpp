#include <stdio.h>

int main () {
	int a;
	int a1, a2, a3;
	scanf("%d", &a);
	a1 = a/100;
	a2 = (a%100)/10;
	a3= a%10;
	if(a1==7 || a2==7 || a3==7) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}