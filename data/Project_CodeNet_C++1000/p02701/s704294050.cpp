#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s]++;
    }
    int ans = 0;
    for (auto u : mp) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}