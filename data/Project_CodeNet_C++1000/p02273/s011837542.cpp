#define _USE_MATH_DEFINES
#include<iostream>
#include<complex>
#include<cmath>
#include <iomanip>
typedef   std::complex<double> Comp_d;
//using Comp_d = std::complex<double>;
void KochCurve(int n, Comp_d p1, Comp_d p2) {
	if (n == 0) { return; }
	Comp_d s = p1 + (p2 - p1) / 3.;
	Comp_d t = p1 + 2.*(p2 - p1) / 3.;
	Comp_d u = s + (t - s)*std::polar(1., M_PI / 3.);
	KochCurve(n - 1, p1, s);
	std::cout << std::fixed << std::setprecision(8) << s.real() << " " << s.imag() << std::endl;;
	KochCurve(n - 1, s, u);
	std::cout << std::fixed << std::setprecision(8) << u.real() << " " << u.imag() << std::endl;;
	KochCurve(n - 1, u, t);
	std::cout << std::fixed << std::setprecision(8) << t.real() << " " << t.imag() << std::endl;;
	KochCurve(n - 1, t, p2);
}
int main(void) {
	int n;
	std::cin >> n;
	std::cout << std::fixed << std::setprecision(8) << 0. << " " << 0. << std::endl;
	KochCurve(n, Comp_d(0., 0.), Comp_d(100., 0.));
	std::cout << std::fixed << std::setprecision(8) << 100. << " " << 0. << std::endl;
	//	system("pause");
	return 0;
}