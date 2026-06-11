#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    bool c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = false;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < n; k++) {
                if (a[i][j] == b[k]) {
                    c[i][j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!c[i][j]) {
                break;
            }
            if (j == 2) {
                goto Exit;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!c[j][i]) {
                break;
            }
            if (j == 2) {
                goto Exit;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (!c[i][i]) {
            break;
        }
        if (i == 2) {
            goto Exit;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (!c[2 - i][i]) {
            break;
        }
        if (i == 2) {
            goto Exit;
        }
    }
    cout << "No" << endl;
    return 0;
Exit:
    cout << "Yes" << endl;
    return 0;
}