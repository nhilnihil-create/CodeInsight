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
    if (a * a * b / (double)2 == x) {
        printf("%.7lf\n", atan(b/a) * (double)360 / ((double)2 * M_PI));
    }
    else if (a * a * b / (double)2 > x) {
        double h = x * (double)2 / b / a;
        printf("%.7lf\n", atan(b/h) * (double)360 / ((double)2 * M_PI));
    }
    else {
        double c = x * (double)2 / a / a - b;
        printf("%.7lf\n", atan((b-c)/a) * (double)360 / ((double)2 * M_PI));
    }
    return 0;
}
