#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][3];
    bool s[3][3];
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            s[i][j] = false;
        }
    }
    int n;
    cin >> n;
    int b[n];
    int k;
    for(i = 0; i < n; i++) {
        cin >> b[i];
        for(j = 0; j < 3; j++) {
            for(k = 0; k < 3; k++) {
                if (b[i] == a[j][k]) {
                    s[j][k] = true;
                }
            }
        }
    }

    string ans = "No";
    for(i = 0; i < 3; i++) {
        bool tmp = true;
        for(j = 0; j < 3; j++) {
            if (s[i][j] == false) {
                tmp = false;
            }
        }
        if (tmp) {
            ans = "Yes";
        }
    }
    for(i = 0; i < 3; i++) {
        bool tmp = true;
        for(j = 0; j < 3; j++) {
            if (s[j][i] == false) {
                tmp = false;
            }
        }
        if (tmp) {
            ans = "Yes";
        }
    }
    if (s[0][0] == true && s[1][1] == true && s[2][2] == true) {
        ans = "Yes";
    }
    if (s[0][2] == true && s[1][1] == true && s[2][0] == true) {
        ans = "Yes";
    }

    cout << ans << endl;
}
