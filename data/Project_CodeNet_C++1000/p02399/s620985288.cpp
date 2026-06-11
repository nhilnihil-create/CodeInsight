#include <iostream>
#include <stdio.h>

int main()
{
	int a, b;
	std::cin >> a >> b;
	printf("%d %d %.5lf\n", a / b, a % b, (double)a / b);
	return 0;
}