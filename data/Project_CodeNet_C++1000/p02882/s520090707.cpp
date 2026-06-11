#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = 3.1415926535897932;
const ll MOD = 1000000007;

int main()
{
    double a, b;
    double x;
    cin >> a >> b >> x;

    bool is_small = x < (a * a * b / 2.0);
    double ans = 0.0;
    if (is_small) {
        double t = (a * b * b) / (2.0 * x);
        ans = atan(t) * 180.0 / PI;
    }
    else {
        double t = (2.0 * a * a * b - 2.0 * x) / (a*a*a);
        ans = atan(t) * 180.0 / PI;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}