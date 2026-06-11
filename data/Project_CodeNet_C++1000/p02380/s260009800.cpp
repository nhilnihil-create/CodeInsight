#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

double CalcH(double b, double C) {
	double H = b*sin(C);
	return H;
}

double CalcS(double a, double h) {
	double S = a * h / 2;
	return S;
}
double CalcL(double a, double b, double C, double h) {
	double x, c, L;

	x = b * cos(C);
	c = sqrt(pow(h, 2.0) + pow((a-x), 2.0));
	L = a + b + c;

	return L;
}
int main() {
	double a, b, C;			// ??\???
	double S, L, h, x, c;	// ??????

	// ??\???
	cin >> a >> b >> C;

	C = (C*M_PI) /180;
	//h = b*sin(C);
	h = CalcH(b, C);

	//S = a * h / 2;
	S = CalcS(a, h);

	//x = b * cos(C);
	//c = sqrt(pow(h, 2.0) + pow((a-x), 2.0));
	//L = a + b + c;
	L = CalcL(a, b, C, h);

	// ??????
	cout << std::fixed << std::setprecision(10) << S << endl;
	cout << std::fixed << std::setprecision(10) << L << endl;
	cout << std::fixed << std::setprecision(10) << h << endl;

	return 0;
}