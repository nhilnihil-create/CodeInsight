#include<stdio.h>
int main(void) {
	int d, t, s;
	scanf("%d%d%d", &d, &t, &s);
	if (d <= t * s) {
		printf("Yes");
	}
	else printf("No");
	return 0;
}