#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, x, theta, pi = acos(-1);
    cin >> a >> b >> x;

    if (x > a * a * b / 2) {
        theta = atan(2 * (a * a * b - x) / (a * a * a));
    } else {
        theta = atan((a * b * b) / (2 * x));
    }
    
    theta *= 180 / pi;

    cout << setprecision(10) << theta;
}