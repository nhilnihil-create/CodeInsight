#include <iostream>

using namespace std;

int main() {
    int ans[1000][11][21], p = 0;
    for (int y = 999; y >= 1; y--) {
        for (int m = 10; m >= 1; m--) {
            int ed = (y % 3 == 0 || (m % 2) == 1) ? 20 : 19;
            for (int d = ed; d >= 1; d--) {
                ans[y][m][d] = ++p;
            }
        }
    }

    int C;
    cin >> C;

    while (C-- > 0) {
        int y, m, d;
        cin >> y >> m >> d;
        cout << ans[y][m][d] << endl;
    }
}