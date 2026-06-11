#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int mx = 0;
    for (auto p : mp) {
        mx = max (p.second, mx);
    }



    for (auto p : mp) {
        if (p.second == mx) {
            cout << p.first << "\n";
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
