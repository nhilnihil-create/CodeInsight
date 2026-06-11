#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
using namespace std;

int main(void){
	double a, b, c;
	double S, L, h;

	cin >> a >> b >> c;

	h = b*sin(c * M_PI / 180);
	S = h * a * 0.5;
	L = a + b + sqrt((a - b*cos(c*M_PI / 180))*(a - b*cos(c*M_PI / 180)) + h*h);

	cout << fixed << setprecision(10) << S << "\n" << L << "\n" << h << "\n";

	return 0;
}