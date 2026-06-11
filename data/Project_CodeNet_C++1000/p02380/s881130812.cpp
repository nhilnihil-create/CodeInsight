#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a, b, deg, rad;
	cin >> a >> b >> deg;
	rad = deg / 180 * 3.141592653589793;
	double bsin = b * sin(rad);
	cout << fixed << setprecision(5);
	cout << a * bsin / 2 << endl;
	cout << a + b + sqrt(a*a + b*b - 2*a*b*cos(rad)) << endl;
	cout << bsin << endl;
}