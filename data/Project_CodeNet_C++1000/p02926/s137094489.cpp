#include <bits/stdc++.h>
using namespace std;

using ld = double;
using point = complex<ld>;

int main() {
    int n; cin >> n;
    vector<point> ps;
    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if(x == 0 && y == 0) continue;
        ps.emplace_back(x, y);
    }
    n = ps.size();
    sort(ps.begin(), ps.end(),
         [] (auto const& a, auto const& b) { return arg(a) < arg(b); });

    ld ans = 0;
    for(int i = 0; i < n; ++i) {
        point p = ps[i];
        ans = max(ans, abs(p));
        for(int j = 1; j < n; ++j) {
            auto const v = ps[(i + j) % n];
            if(arg(v / ps[i]) < 0) break;
            p += v;
            ans = max(ans, abs(p));
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
}
