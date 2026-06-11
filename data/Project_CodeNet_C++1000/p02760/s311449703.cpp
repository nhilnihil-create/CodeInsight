#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    int n;
    cin >> n;

    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (a[x][y] == b) a[x][y] = 0;
            }
        }
    }

    bool r = false;
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) r = true;
    }
    for (int i = 0; i < 3; i++) {
        if (a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0) r = true;
    }
    if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) r = true;
    if (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0) r = true;
    
    if (r) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
