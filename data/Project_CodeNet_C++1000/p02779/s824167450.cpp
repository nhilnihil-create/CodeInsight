#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] > 1) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
