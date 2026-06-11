#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double ans = 0.0, ang = 0.0;
    ang = abs(0.5 * (h * 60 + m) - 6.0 * m);
    ang = min(ang, abs(360.0 - ang));
    ans = a * a + b * b - 2.0 * a * b * cos(M_PI * ang / 180);
    ans = pow(ans, 0.5);
    cout << fixed << setprecision(13);
    cout << ans << endl;
    return 0;
}