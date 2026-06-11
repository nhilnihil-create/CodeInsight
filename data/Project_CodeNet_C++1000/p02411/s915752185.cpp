#include<stdio.h>
int main(void) {
	int a = 1,b,c,d,e=0,f;
	char r[50];
	while (a) {
		scanf("%d %d %d", &b, &c, &d);
		if (b == -1 && c == -1 && d == -1) {
			a = 0;
		}
		else if (b == -1 || c == -1) {
			r[e] = 'F';
			e++;
		}
		else if (b + c >= 80) {
			r[e] = 'A';
			e++;
		}
		else if (65 <= b + c && b + c < 80) {
			r[e] = 'B';
			e++;
		}
		else if (50 <= b + c && b + c < 65) {
			r[e] = 'C';
			e++;
		}
		else if (30 <= b + c && b + c < 50 && 50<=d) {
			r[e] = 'C';
				e++;
		}
		else if (30 <= b + c && b + c < 50 && d < 50) {
			r[e] = 'D';
			e++;
		}
		else {
			r[e] = 'F';
			e++;
		}
	}
	for (f = 0; f < e; f++) {
		printf("%c\n", r[f]);
	}
	return 0;
}
