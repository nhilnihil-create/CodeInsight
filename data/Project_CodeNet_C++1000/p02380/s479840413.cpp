#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926535

int main(){
	long a, b, C;
	cin >> a >> b >> C;
	double S, L, h;
	double radC;
	radC = PI / 180.0 * C;
	S = 0.5 * a * b * sin(radC);
	L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(radC));
	h = b * sin(radC);
	cout << fixed << S << endl << L << endl << h << endl;
	return 0;
}