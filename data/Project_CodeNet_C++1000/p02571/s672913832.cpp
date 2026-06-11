#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string s, t;
    cin >> s >> t;
    int ans = 1000;
    for (int i = 0; i < s.size() - t.size() + 1; ++i) {
        int replace = 0;
        for (int j = 0; j < t.size(); ++j) {
            if (s[i+j] != t[j]) ++replace;
        }
        ans = min(ans, replace);
    }
    cout << ans << endl;
}