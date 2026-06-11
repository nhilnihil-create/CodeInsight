#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    if (x * (double)2 <= a * a * b) {
        double h = x / a / b * (double)2;
        double ang = atan(b/h) * (double)360 / ((double)2 * M_PI);
        printf("%.7lf\n", ang);
    }
    else {
        double h = (double)2 * x / a / a - b;
        double ang = atan((b-h)/a) * (double)360 / ((double)2 * M_PI);
        printf("%.7lf\n", ang);
    }
    return 0;
}
