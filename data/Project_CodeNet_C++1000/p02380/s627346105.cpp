/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_B
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

const double PI = 3.1415926535897932;

int
main()
{
    ios::sync_with_stdio(false);
    constexpr int d = numeric_limits<float>::max_digits10;
    
    double a, b;
    int C;
    cin >> a >> b >> C;

    double c = C * PI / 180;
    cout << setprecision(d) << fixed;
    cout << a * b * sin(c) / 2 << endl;
    cout << a + b + sqrt(a * a + b * b - 2 * a * b * cos(c)) << endl;
    cout << b * sin(c) << endl;

    return 0;
}