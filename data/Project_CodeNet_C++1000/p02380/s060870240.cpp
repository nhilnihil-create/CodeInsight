#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    double a, b, C;
    cin >> a >> b >> C;
    double S, L, h,r;
    r = C*3.14159265359/ 180;
    S = a*b*sin(r) / 2;
    L = sqrt(pow(a, 2) + pow(b, 2) - 2 * a*b*cos(r))+a+b;
    h = S * 2 / a;
    cout << setprecision(10);
    cout << S << endl; cout << setprecision(10); 
    cout << L << endl; cout << setprecision(10);
    cout<< h << endl;
    return 0;
}