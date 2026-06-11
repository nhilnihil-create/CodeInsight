#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;

    double ans;
    if (x <= a * b / 2.0)
        ans = M_PI_2 - atan(2.0 * x / (b * b));
    else
        ans = atan(2 * (a * b - x) / (a * a));
    printf("%.10lf\n", ans * 180 / M_PI);
}