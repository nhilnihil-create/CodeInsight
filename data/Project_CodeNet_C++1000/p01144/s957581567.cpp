#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n, m;

void solve() {
    vector<pair<int, int>> vec;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int d, p;
        cin >> d >> p;
        // -p ??¨??????????????????????????°???????????????????????§??????
        vec.push_back(make_pair(-p, d));
    }
    sort(vec.begin(), vec.end());

    for (auto e : vec) {
        int p = -e.first;
        int dist = e.second;
        if (m - dist < 0) {
            ans += (dist - m) * p;
            m = 0;
        } else {
            m -= dist;
        }
    }
    cout << ans << endl;
}

int main() {
    while (cin >> n >> m) {
        if (n + m == 0) return 0;
        solve();
    }

    return 0;
}