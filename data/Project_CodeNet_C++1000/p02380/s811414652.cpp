#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() 
{
	int a, b, C;
	double S, L, h, PI;
	PI = 3.14159265358979;
	cin >> a >> b >> C;
	S = 0.5 * a * b * sin(C * PI / 180);
	L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C * PI / 180));
	h = b * sin(C * PI / 180);
	cout << fixed << setprecision(8) << S << endl;
	cout << fixed << setprecision(8) << L << endl;
	cout << fixed << setprecision(8) << h << endl;
	return 0;
}
