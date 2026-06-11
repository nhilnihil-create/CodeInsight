#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, D;
    cin >> M >> D;
    int res = 0;
    for (int m = 4; m <= M; m++) {
        for (int d = 22; d <= D; d++) {
            int d1 = d % 10, d10 = d / 10;
            if (d1 >= 2 && d10 >= 2 && d1 * d10 == m)
                res++;
        }
    }
    cout << res << '\n';

    return 0;
}