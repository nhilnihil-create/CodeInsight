#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    double a, b, c, h, m;
    cin >> a >> b >> h >> m;
    c = a * a + b * b - 2 * a * b * cos(abs((m * 6) - (h * 30 + 0.5 * m)) * M_PI / 180);
    cout << setprecision(11) << sqrt(c) << endl;
}