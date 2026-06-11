// 69

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

#define _USE_MATH_DEFINES

int main(){
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    long double rad, ans;
    rad = abs(h*M_PI/6 + m*M_PI/360 - m*M_PI/30);
    ans = sqrt(pow(abs(a*cos(rad)-b), 2) + pow(a*sin(rad), 2));
    cout << fixed << setprecision(11) << ans << endl;
    return 0;
}
