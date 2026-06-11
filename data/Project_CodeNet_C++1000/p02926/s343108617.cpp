#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int, int> > ps;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x != 0 || y != 0) ps.push_back({x, y});
    }
    sort(ps.begin(), ps.end(), [&](auto &p, auto &q) {
            return atan2(p.second, p.first) < atan2(q.second, q.first);
        });
    n = ps.size();
    ps.insert(ps.end(), ps.begin(), ps.end());
    long long ans2 = 0;
    for (int i = 0; i < n; i++) {
        long long x = 0, y = 0;
        for (int j = i; j < i+n; j++) {
            x += ps[j].first, y += ps[j].second;
            ans2 = max(ans2, x*x + y*y);
        }
    }
    cout << setprecision(16) << sqrt(ans2) << endl;
}
