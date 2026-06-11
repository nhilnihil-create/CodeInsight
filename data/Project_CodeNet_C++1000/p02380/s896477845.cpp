#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.1415926535

using namespace std;

int main(void){
	
	double a, b, c, angle, s, l, h;
	cin >> a >> b >> angle;

	angle = angle*PI / 180.0;
	s = a*b*sin(angle)/2.0;
	c = sqrt(pow(a, 2)+pow(b, 2) - 2*a*b*cos(angle));
	l = a + b + c;
	h = b*sin(angle);

	cout << fixed << setprecision(10);
	cout << s << "\n" << l << "\n" << h << "\n";
	cin >> a;
	return 0;
}