#include <stdio.h>
#include <iostream>

int main()
{
	long long a, b, r=1, temp;
	long long A, B;

	std::cin >> a >> b;

	A = a; B = b;

	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}


	while (r != 0)
	{
		r = a % b;
		a = a / b;
		a = b;
		b = r;
	}


	std::cout << A*B/a << std::endl;
}