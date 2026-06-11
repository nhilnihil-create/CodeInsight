#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool top[10];
    bool mid[10][10];
    bool bottom[10][10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) bottom[i][j][k] = false;
            mid[i][j] = false;
        }
        top[i] = false;
    }
    int ans = 0;
    for (char c: s) {
        int now = c - '0';
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (mid[i][j] && !bottom[i][j][now]) {
                    ans++;
                    bottom[i][j][now] = true;
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            if (top[i] && !mid[i][now]) mid[i][now] = true;
        }
        if (!top[now]) top[now] = true;
    }
    cout << ans << endl;
    return 0;
}