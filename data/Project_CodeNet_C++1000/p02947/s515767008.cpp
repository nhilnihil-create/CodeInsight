#include <bits/stdc++.h>
using namespace std;

typedef vector<int8_t> T;


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<T, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        T v(26, 0);
        string s;
        cin >> s;
        for (auto &c : s)
            v[c - 'a']++;
        ans += cnt[v]++;
    }
    cout << ans << endl;
    return 0;
}