// @author: arch_

#include <bits/stdc++.h>
using namespace std;

int w, h, x, y, r;

void solve() {
    int cx[] = {x, x, x - r, x + r};
    int cy[] = {y - r, y + r, y, y};
    for (int i = 0; i < 4; i++)
        if (!(0 <= cx[i] && cx[i] <= w
              && 0 <= cy[i] && cy[i] <= h)) {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}

int main(void) {
    cin >> w >> h >> x >> y >> r;
    solve();
    return 0;
}