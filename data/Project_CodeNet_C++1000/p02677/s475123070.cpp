#include <bits/stdc++.h>
using namespace std;
using ld = double;
const ld PI = acos(-1);

int main()
{
    double a, b, h, m;
    cin >> a >> b >> h >> m;

    double rad = abs((60 * h + m) / 720 * 2 * PI) - (m / 60 * 2 * PI);
    double res = sqrt(a * a + b * b - 2 * a * b * cos(rad));

    cout << fixed << setprecision(10) << res << "\n";
    return 0;
}