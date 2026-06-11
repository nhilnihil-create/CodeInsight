#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<vector<int>, long long> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> abc(27);
        for (char c : s) abc[c-'a']++;
        mp[abc]++;
    }
    long long ans = 0;
    for (auto m: mp) {
        ans += m.second * (m.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}