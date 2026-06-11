#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    double a,b,c;
    double p=3.1415926535;
    cin >> a >> b >> c;
    cout << fixed << setprecision(7) << a*b*sin(c*p/180)/2 << endl;
    cout << fixed << setprecision(7) << a+b+sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c*p/180)) << endl;
    cout << fixed << setprecision(7) << a*b*sin(c*p/180)/a << endl;
    return 0;
}

