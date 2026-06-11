#include <iostream>
#include <iomanip>
#include <cmath>

const double PI = 4*atan(1);

int main(){
	double a, b, c, rad_C, S, L, h;
	int deg_C;
	std::cin >> a >> b >> deg_C;
	rad_C = deg_C * PI / 180;
	S = a * b * sin(rad_C) / 2;
	c = sqrt(a * a + b * b - 2 * a * b * cos(rad_C));
	L = a + b + c;
	h = 2 * S / a;
	std::cout << std::fixed << S << '\n' << L << '\n' << h << std::endl;
	return 0;
}