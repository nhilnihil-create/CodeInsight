#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < (sz(s) + 1) / 4; i++) {
        if (s[i] != s[sz(s) / 2 - i - 1] ||
                s[i] != s[sz(s) / 2 + i + 1] ||
                s[i] != s[sz(s) - i - 1]) {
            return cout << "No", 0;
        }
    }
    cout << "Yes";
}
