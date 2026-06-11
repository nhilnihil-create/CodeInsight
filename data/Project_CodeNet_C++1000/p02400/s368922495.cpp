#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    const double pi = acos(-1);
    double r;
    cin >> r;
    cout << fixed << setprecision(8);
    cout << r * r * pi << " " << 2 * r * pi << "\n";
}