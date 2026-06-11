#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926535;

void solve(int a, int b, int x)
{
    cout << fixed << setprecision(10);
    double theta;
    if (x < (double)a * a * b / 2.0)
    {
        theta = PI / 2.0 - atan((2.0 * x) / ((double)a * b * b));
    }
    else
    {
        theta = atan((2.0 * b - (2.0 * x) / ((double)a * a)) / a);
    }
    cout << 180.0 * theta / PI << endl;
}

int main()
{
    int a;
    cin >> a;
    int b;
    cin >> b;
    int x;
    cin >> x;
    solve(a, b, x);
    return 0;
}
