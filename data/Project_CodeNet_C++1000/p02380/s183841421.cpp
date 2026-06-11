#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << setprecision(10) << a * sin(c / 360.0 * 2 * M_PI) * b * 0.5 << endl;
    cout << a + b + sqrt(a * a + b * b - 2 * a * b * cos(c / 360.0 * 2 * M_PI)) << endl;
    cout << b * sin(c / 360.0 * 2 * M_PI) << endl;
}