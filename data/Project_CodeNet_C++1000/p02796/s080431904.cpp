#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        p[i].first = x + l;
        p[i].second = x - l;
    }
    sort(p.begin(), p.end());
    int right = -1e9 - 10000;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].second >= right) {
            right = p[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}