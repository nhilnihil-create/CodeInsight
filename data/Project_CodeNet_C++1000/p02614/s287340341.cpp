#include <bits/stdc++.h>

using namespace std;

char s[10][10];
int ans[100][100];

long long sum = 0;
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    for (int i = 1; i <= h; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int l = 0; l < (1 << w) - 1; l++) {
        ans[l][0] = 1;
        for (int i = 1; i <= h; i++) {
            int cnt = 0;
            for (int j = 1; j <= w; j++) {
                if ((l & (1 << (j - 1))) == 0 && s[i][j] == '#') {
                    cnt++;
                }
            }
            for (int j = k - cnt; j >= 0; j--) {
                ans[l][j + cnt] = ans[l][j + cnt] + ans[l][j];
            }
        }
        sum += ans[l][k];
    }
    cout << sum << endl;
    return 0;
}