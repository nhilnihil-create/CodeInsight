#include <stdio.h>

int main() {
	long long max;
	long a, b, c, d;

	scanf("%ld%ld%ld%ld", &a, &b, &c, &d);

	max = a * c;
	max = (max < a * d) ? a * d : max;
	max = (max < b * c) ? b * c : max;
	max = (max < b * d) ? b * d : max;

	printf("%ld", max);

	return 0;
}