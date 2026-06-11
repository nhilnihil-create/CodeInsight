#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[2010][2010];
int cnt[2010];
int main() {
    int n,x,y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (j <= x || i >= y) {
                d[i][j] = j - i;
                continue;
            }
            if (i <= x && j >= y) {
                d[i][j] = x - i + j - y + 1;
                continue;
            }
            if (i <= x) {
                d[i][j] = min(j - i, y - j + 1 + x - i);
                continue;
            }
            if (j >= y) {
                d[i][j] = min(j - i, j - y + 1 + i - x);
                continue;
            }
            d[i][j] = min(j - i, i - x + y - j + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cnt[d[i][j]]++;
        }
    }
    for (int i = 1; i <= n - 1; i++) cout << cnt[i] << endl;
    return 0;
}