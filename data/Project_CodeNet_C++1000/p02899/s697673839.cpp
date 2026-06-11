#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    for (auto p : a) {
        cout << p.second + 1 << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
