#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;
    int s[m], c[m];
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> c[i];
    }

    char num[5];
    for (int i = 0; i < 5; i++) {
        num[i] = 0;
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
        if ((s[i] == 1) && (c[i] == 0)) {
            ok = false;
            break;
        } else if ((num[s[i]] != 0) && (num[s[i]] != c[i] + '0')) {
            ok = false;
            break;
        } else {
            num[s[i]] = c[i] + '0';
        }
    }
    if (num[1] == 0) {
        num[1] = '1';
    }
    for (int i = 2; i <= n; i++) {
        if (num[i] == 0) {
            num[i] = '0';
        }
    }

    bool zero = false;
    if (n == 1) {
        zero = true;
        if (m == 0) {
            ;
        } else {
            for (int i = 0; i < m; i++) {
                if (c[i] != 0) {
                    zero = false;
                    break;
                }
            }
        }
    }
    if (ok && !zero) {
        for (int i = 1; i <= n; i++) {
            cout << num[i];
        }
        cout << endl;
    } else if (zero) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}