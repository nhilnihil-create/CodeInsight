#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define PI 3.14159265358979323846
using namespace std;

int main() {
    long double a, b, h, m;
    cin >> a >> b >> h >> m;

    long double rad = (30 * h + m / 2 - 6 * m) * PI / 180;

    long double d = (a * a + b * b) - 2 * a * b * cos(rad);

    cout << fixed << setprecision(20) << sqrt(d) << endl;


}