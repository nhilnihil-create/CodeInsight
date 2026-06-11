#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;
using ull = unsigned long long;

int main()
{
    double x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    auto xdist = x1 - x2;
    auto ydist = y1 - y2;

    cout << setprecision(10) << sqrt(xdist * xdist + ydist * ydist) << endl;

    return 0;
}