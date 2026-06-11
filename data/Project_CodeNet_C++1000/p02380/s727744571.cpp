#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    double a, b, C;
    cin >> a >> b >> C;
    C *= M_PI / 180;
    
    double h = b * sin(C);
    double S = a * h / 2;
    double c = sqrt(a*a + b*b - 2 * a * b * cos(C));
    double L =  a + b + c;
    cout << fixed << setprecision(4);
    cout << S << endl;
    cout << L << endl;
    cout << h << endl;
    return 0;
}