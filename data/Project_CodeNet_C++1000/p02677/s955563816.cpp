#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

#define int long long

signed main() { 
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    double rad = 2 * M_PI * (h / 12.0 + m / 720.0 - m / 60.0); 
 
    double ans = sqrt(a * a + b * b  - 2 * a * b * cos(rad));

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
