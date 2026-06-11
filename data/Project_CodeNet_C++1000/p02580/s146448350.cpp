#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<pair<int, int>> bombs;
    vector<pair<int, int>> l, r;
    for (int i = 0; i < h; i++) l.emplace_back(0, i);
    for (int i = 0; i < w; i++) r.emplace_back(0, i);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        l[x].first++, r[y].first++;
        bombs.emplace_back(x, y);
    }
    sort(l.begin(), l.end(), greater<pair<int, int>>());
    sort(r.begin(), r.end(), greater<pair<int, int>>());
    set<int> lmax, rmax;
    for (int i = 0; i < h; i++) {
        if (l[i].first < l[0].first) break;
        lmax.insert(l[i].second);
    }
    for (int i = 0; i < w; i++) {
        if (r[i].first < r[0].first) break;
        rmax.insert(r[i].second);
    }
    // cout << endl;
    // for (auto a: lmax) cout << a << ' ';
    // cout << endl;
    // for (auto a: rmax) cout << a << ' ';
    // cout << endl;

    int max_bombs = 0;
    for (auto b: bombs) {
        if (lmax.count(b.first) == 0) continue;
        if (rmax.count(b.second) == 0) continue;            
        // cout << b.first << ' ' << b.second << endl;
        max_bombs++;
    }
    int ans = l[0].first + r[0].first - 1;
    if (max_bombs < lmax.size() * rmax.size()) ans++;
    cout << ans << endl;
    return 0;
}