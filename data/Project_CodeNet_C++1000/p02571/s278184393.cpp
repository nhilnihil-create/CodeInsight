#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = t.length();
    int m = s.length();
    int ans = 2000;
    for (int start = 0; start <= m - n; ++start) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[start + i] != t[i])
                res++;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
