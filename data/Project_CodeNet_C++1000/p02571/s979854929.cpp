#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int ans = s.size();
    for (int i = 0; i + t.size() - 1 <= s.size() - 1; i++) {
        string cur = s.substr(i, t.size());
        int tmp = 0;
        for (int i = 0; i < t.size(); i++) {
            if (cur[i] != t[i]) tmp++;
        }
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}