#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    double a, b, x;
    cin >> a >> b >> x;
    if (x < a * a * b / 2)
        cout << fixed << setprecision(10) << atan(a * b * b / (2 * x)) * 180 / M_PI << endl;
    else
        cout << fixed << setprecision(10) << atan(2 / a * (b - x / (a * a))) * 180 / M_PI << endl;
    return 0;
}