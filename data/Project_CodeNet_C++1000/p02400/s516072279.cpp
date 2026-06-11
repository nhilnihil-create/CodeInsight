#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    double r;
    cin >> r;

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << M_PI * r * r << ' ' << 2 * M_PI * r << endl;

    return 0;
}