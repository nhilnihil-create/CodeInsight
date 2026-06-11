#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<pair<int, int>> apples;
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        apples.push_back({x, 0});
    }
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        apples.push_back({x, 1});
    }
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        apples.push_back({x, 2});
    }
    sort(apples.begin(), apples.end());
    int tot = 0;
    int sp = 0;
    for (int i = apples.size() - 1; i >= 0; i--) {
        if (x + y - sp == 0) break;
        if (apples[i].second == 0) {
            if (x > 0) {
                x--;
                tot += apples[i].first;
            }
        } else if (apples[i].second == 1) {
            if (y > 0) {
                y--;
                tot += apples[i].first;
            }
        } else {
            sp++;
            tot += apples[i].first;
        }
    }
    cout << tot << '\n';

    fflush(stdout);
    return 0;
}
