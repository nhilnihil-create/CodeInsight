#include<stdio.h>
int a, b;
int main()
{
	int c,d=0,e=0;
	while (scanf("%d", &c) != 0) {
		if (c == 0)break;
		for (int i = 1; i <= c; i++) {
			scanf("%d %d", &a, &b);
			if (a > b)d += a + b;
			else if (a < b)e += a + b;
			else {
				d += a;
				e += b;
			}
		}
		printf("%d %d\n", d, e);
		d = e = 0;
	}
}