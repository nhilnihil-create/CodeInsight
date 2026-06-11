#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int s[5];
    char c[5];
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> s[i] >> c[i];

    if (n == 1 && m == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (m == 0) {
        cout << pow(10, n - 1) << endl;
        return 0;
    }

    int ans = 1000;
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            if (s[i] == 1 && c[i] == '0') ans = 0;
            else break;
        }
    }
    if (ans != 1000) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = pow(10, n - 1); i < pow(10, n); i++) {
        string str = to_string(i);
        for (int j = 0; j < m; j++) {
            if (str.at(s[j] - 1) != c[j]) break;
            if (j == m - 1) ans = i;
        }
        if (ans == i) {
            cout << ans << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}