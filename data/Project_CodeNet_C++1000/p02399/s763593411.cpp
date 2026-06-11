#include <stdio.h>

int main(int argc, char** argv)
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d %d %.5f", a / b, a % b, static_cast<double>(a) / b);

	return 0;
}
