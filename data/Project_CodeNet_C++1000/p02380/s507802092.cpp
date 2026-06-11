#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){
	long double a,b,C360;
	cin >> a >> b >> C360;
	long double C = C360 / 360 * 2 * 3.1415926535897932384626;
	long double h = b * sin(C);
	long double x = sqrt(b * b + a * a -  2 * a * b * cos(C));
	long double L = a + b + x;
	long double S = a * h / 2;
	cout << fixed << setprecision(8) << S << endl;
	cout << fixed << setprecision(8) << L << endl;
	cout << fixed << setprecision(8) << h << endl;
	return 0;
}