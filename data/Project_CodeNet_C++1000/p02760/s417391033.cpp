#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[3][3];

int main() {
    for (int i = 0; i < 9; i++) cin >> a[i / 3][i % 3];
    int n, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b;
        for (int j = 0; j < 9; j++) {
            if (a[j / 3][j % 3] == b) a[j / 3][j % 3] = 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        int col = 0, row = 0;
        for (int j = 0; j < 3; j++) {
            col += a[j][i], row += a[i][j];
        }
        if (col == 0 || row == 0) {
            puts("Yes");
            return 0;
        }
    }
    if (a[0][0] + a[1][1] + a[2][2] == 0 || a[0][2] + a[1][1] + a[2][0] == 0) {
        puts("Yes");
        return 0;
    }
    puts("No");
}
