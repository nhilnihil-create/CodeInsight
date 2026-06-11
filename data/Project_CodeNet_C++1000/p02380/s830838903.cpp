#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
    
int main()
{
	double a, b, h;
	int C;
	cin >> a >> b >> C ;
	h = b * sin(M_PI * C / 180);
	cout << fixed << setprecision(4)
		 << a * h / 2 << ' '
		 << a + b + sqrt( pow(h,2) + pow(a - b * cos(M_PI * C / 180),2)) << ' '
		 << h
		 << endl;
	return 0;
}