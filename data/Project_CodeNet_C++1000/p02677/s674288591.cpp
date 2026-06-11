#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    double a, b, h, m, c;
    cin >> a >> b >> h >> m;
    h = h * 30 + m / 2;
    m = m * 6;
    c = min(abs(h - m), 360 - abs(h - m));
    c /= 180 / 3.14159265358979;
    cout << setprecision(13) << sqrt(a * a + b * b - 2 * a * b * cos(c));
}
