#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#define PI 3.14159265
using namespace std;

int main()
{
    double a, b, c;

    cin >> a >> b >> c;

    double s = a*b*sin(c*PI/180)/2;
    double h = b*sin(c*PI/180);
    double l = sqrt( a*a + b*b - 2*a*b*cos(c*PI/180) ) + a + b;

    cout << fixed << setprecision(8) << s << "\n" ;
    cout << fixed << setprecision(8) << l << "\n" ;
    cout << fixed << setprecision(8) << h << "\n" ;

	return 0;
}
