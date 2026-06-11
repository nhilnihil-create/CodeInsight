#include <iostream>
#include <string>

int main()
{
	double a, b, r, f;
	int A, B, d;
	std::cin >> a >> b;
	A = a;
	B = b;
	f = a / b;
	a *= 1.000000;
	b *= 1.000000;
	d = A / B;
	r = A % B;
	std::cout << d << " " << r << " " << std::fixed << f << std::endl;
}