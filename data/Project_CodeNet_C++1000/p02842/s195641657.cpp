#include <stdio.h>
using namespace std;
using ll = long long;

int main(void) {
	int X;
	scanf("%d", &X);
	int Y = X * 100 / 108;
	if (Y * 108 / 100 == X) {
		printf("%d\n", Y);
	} else if (++Y * 108 / 100 == X) {
		printf("%d\n", Y);
	} else {
		printf(":(\n");
	}
	return 0;
}
