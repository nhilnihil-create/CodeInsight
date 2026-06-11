#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main(){
	double a, b, c, C;
	cin >> a >> b >> C;

	c = C * 3.1415926535 / 180 ;
	
	cout << fixed << setprecision(8) << a * b * sin(c) * 0.5 << endl;
	cout << fixed << setprecision(8) << a + b + sqrt(a*a + b*b - 2*a*b*cos(c)) << endl;
	cout << fixed << setprecision(8) << b * sin(c) << endl;
	
	return 0;
}