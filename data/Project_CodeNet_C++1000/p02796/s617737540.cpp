#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> gs(n);
    for (int i=0; i<n; ++i) {
        int x, l; cin >> x >> l;
        int g = x+l;
        int s = x-l;
        gs[i] = make_pair(g, s);
    }
    sort(gs.begin(), gs.end());
    int ans = 1;
    int now = gs[0].first;
    for (int i=1; i<n; ++i) {
        if (now > gs[i].second) continue;
        else {
            ans++;
            now = gs[i].first;
        }
    }
    cout << ans << endl;
}