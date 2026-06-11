#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n, m;
    cin >> n >> m;
    int s[m], c[m];
    map<int, int> mp;
    rep(i, 0, m) {
        cin >> s[i] >> c[i];
        if (s[i] > n) {
            cout << -1 << endl;
            return 0;
        }
        if (mp[s[i]]) {
            if (mp[s[i]] != c[i]) {
                cout << -1 << endl;
                return 0;
            }
        } else {
            mp[s[i]] = c[i];
        }
        if (n >= 2 && s[i] == 1 && c[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    string ans(n, '0');
    for (auto i : mp) {
        int d = i.first - 1;
        int num = i.second;
        ans[d] = char(num + '0');
    }
    if (n >= 2 && ans[0] == '0') ans[0] = '1';
    cout << ans << endl;
    return 0;
}
