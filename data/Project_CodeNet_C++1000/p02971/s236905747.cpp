#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort (a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (a[j].second == i) j++;
        cout << a[j].first << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
