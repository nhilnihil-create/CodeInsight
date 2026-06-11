#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){

	int a, b, C;
	cin >> a >> b >> C;

	double pi, S, L, h;

	pi = atan(1.0) * 4.0;

	h = b * sin(pi * C / 180);

	S = a * h / 2;

	L = a + b + sqrt(pow(a - b * cos(pi * C / 180), 2) + pow(h, 2));

	cout << fixed << S << endl;
	cout << fixed << L << endl;
	cout << fixed << h << endl;

	return 0;
}