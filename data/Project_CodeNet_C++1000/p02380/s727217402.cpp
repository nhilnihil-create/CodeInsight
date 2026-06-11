#include <iostream>
#include <math.h>
#include <iomanip>
#define PI 3.141592653589793
using namespace std;

int main()
{
	double a,b,C,S,L,h,R;
	cin >> a >> b >> C;

	R = C * PI / 180.0;

	S = (a*b*sin(R))/2;
	L = a + b + sqrt((a*a) + (b*b) - (2*a*b*cos(R)));
	h = b*sin(R);

	
	cout << fixed << std::setprecision(6) << S << endl;
	cout << fixed << std::setprecision(6) << L << endl;
	cout << fixed << std::setprecision(6) << h << endl;

	return 0;
}