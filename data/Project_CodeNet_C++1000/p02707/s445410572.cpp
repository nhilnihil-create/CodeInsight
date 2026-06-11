#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        --x;
        ans[x]++;
    }
    for (auto x : ans) {
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
