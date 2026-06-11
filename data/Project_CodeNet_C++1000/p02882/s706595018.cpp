#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    double a, b, x;
    cin >> a >> b >> x;
    if (x * 2 < a * a * b) {
        x /= a;
        x *= 2;
        x /= b;
        cout << setprecision(13) << atan(b / x) / 3.141592653589793 * 180;
    } else {
        //y=x*2/a/a-b
        double y = x * 2 / a / a - b;
        cout << setprecision(13) << atan((b - y) / a) / 3.141592653589793 * 180;
    }
}
