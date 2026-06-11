#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    double w, h, x, y;
    cin >> w >> h >> x >> y;

    double ans1 = 0.0;
    ans1 = w * h / 2;

    int ans2 = 0;
    if((x == w / 2) && (y == h / 2)) {
        ans2 = 1;
    }

    cout << fixed << setprecision(15) << ans1 << " " << ans2 << endl;
}