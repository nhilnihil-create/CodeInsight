#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

constexpr double PI = acos(-1);

int main()
{

    int a, b, C;
    cin >> a >> b >> C;

    double S = 0.5 * a * b * sin(C*PI/180);
    double c = sqrt(a*a + b*b -2*a*b*cos(C*PI/180));
    double h = b*sin(C*PI/180);
    cout << fixed;
    cout << S << endl;
    cout << a+b+c << endl;
    cout << h << endl;
}
