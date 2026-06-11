#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	int m = (int)(n / 10);
	switch (n - m * 10) {
	case 0:
	case 1:
	case 6:
	case 8:
		printf("pon");
		break;
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		printf("hon");
		break;
	case 3:
		printf("bon");
		break;
	}
}