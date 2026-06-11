#include <iostream>
#include <math.h>
#define PI 3.141592653589793

using namespace std;

double transToRadian( double degree ){
	double radian = degree * PI / 180.0;

	return radian;
}

int main(){
	 double a, b, c;
	 cin >> a;
	 cin >> b;
	 cin >> c;

	 double sinC = sin( transToRadian(c) );
	 double cosC = cos( transToRadian(c) );

	 double S = a * b * sinC / 2;

	 double L = a + b+ sqrt( a * a + b * b - 2 * a * b * cosC );

	 double h = b * sinC;

	 cout << fixed << S << endl;
	 cout << fixed << L << endl;
	 cout << fixed << h << endl;
}