#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double a, b, d;
	cin >> a >> b >> d;
	double s = a * b * sin(d *= M_PI / 180) / 2;
	cout << fixed << setprecision(10) << s << endl;
	double c = sqrt(a * a + b * b - 2 * a * b * cos(d));
	cout << fixed << setprecision(10) << a + b + c << endl;
	cout << fixed << setprecision(10) << b * sin(d) << endl;
}