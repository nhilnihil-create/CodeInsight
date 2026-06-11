#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	double a, b, c;
	double s, l, h;
	
	cin >> a >> b >> c;
	
	s=0.5*a*b*sin((M_PI/180)*c);
	l=a+b+sqrt(a*a+b*b-(2*a*b*cos((M_PI/180)*c)));
	h=2*s/a;
	
	cout << fixed << setprecision(4) << s << endl;
	cout << fixed << setprecision(4) << l << endl;
	cout << fixed << setprecision(4) << h << endl;
	
	return 0;
}