#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<long long> s;
    int h, w;
    cin >> h >> w;
    vector<int> cr(h), cc(w);
    int m;
    cin >> m;
    for (int i = 0 ; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        ++cr[r]; ++cc[c];
        s.insert(1LL * r * w + c);
    }
    vector<pair<int, int>> rs, cs;
    for (int i = 0; i < h; ++i) if (cr[i]) rs.emplace_back(cr[i], i);
    for (int i = 0; i < w; ++i) if (cc[i]) cs.emplace_back(cc[i], i);
    sort(rs.rbegin(), rs.rend());
    sort(cs.rbegin(), cs.rend());
    int ans = 0, l = cs.size();
    for (auto r : rs) {
        int best = -1;
        for (int i = 0; i < l; ++i) {
            int tot = r.first + cs[i].first;
            if (tot <= ans) break;
            if (s.find(1LL * r.second * w + cs[i].second) != s.end()) {
                --tot;
                ans = max(ans, tot);
            } else {
                ans = max(ans, tot);
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}