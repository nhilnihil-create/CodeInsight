#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long double ld;

int main() {
    int n;
    cin >> n;

    int count = 0;
    vector<vector<ld>> v;
    for (int i = 0; i < n; i++) {
        ld x, y;
        cin >> x >> y;
        if (x != 0 || y != 0) {
            count++;
            ld theta = atan2(y, x);
            v.push_back({theta - 2 * M_PI, x, y});
            v.push_back({theta, x, y});
            v.push_back({theta + 2 * M_PI, x, y});
        }
    }
    sort(v.begin(), v.end());

    long long ret = 0;
    for (int i = 0; i < v.size(); i++) {
        vector<long long> now(2);
        for (int j = i; j < v.size() && j - i + 1 <= count; j++) {
            now[0] += v[j][1], now[1] += v[j][2];
            ret = max(ret, now[0] * now[0] + now[1] * now[1]);
        }
    }
    cout << fixed << setprecision(20) << sqrt(ret) << endl;
    return 0;
}