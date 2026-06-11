#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a;
    cin >> a;

    double resA,resB;
    resA = a * a * M_PI;
    resB = 2.0 * a * M_PI;

    cout << fixed << resA << " " << fixed << resB << endl;

    return 0;
}