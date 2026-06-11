#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    unordered_map<string, long long> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    long long ans = 0;
    for (auto p : mp) {
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
