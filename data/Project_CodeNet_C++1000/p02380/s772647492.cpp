#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
	double a;
	double b;
	double C;
	cin >> a;
	cin >> b;
	cin >> C;
	double d;
	d = C * 3.1415926535 / 180;
	cout << fixed << a * b * sin(d) / 2 << endl;
	cout << fixed << a + b + sqrt( a*a+b*b-a*b*cos(d)*2 ) << endl;
	cout << fixed << b * sin(d) << endl;
	return 0;
}