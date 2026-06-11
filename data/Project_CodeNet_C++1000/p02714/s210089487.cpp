#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    long cr = 0, cb = 0, cg = 0;
    for (char c : s) {
        if (c == 'R') cr++;
        if (c == 'G') cg++;
        if (c == 'B') cb++;
    }
    long res = cr * cg * cb;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = j + (j - i);
            if (k < n) {
                if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) {
                    res--;
                }
            }
        }
    }
    cout << res << "\n";

    return 0;
}