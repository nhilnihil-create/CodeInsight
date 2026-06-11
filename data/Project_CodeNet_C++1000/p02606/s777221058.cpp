#include <iostream>

using namespace std;

int solve(int l, int r, int d) {
    int cnt = 0;
    for (int i = l; i <= r; i ++) {
        if (i % d == 0) cnt ++;
    }

    return cnt;
}

int main() {
    int l, r, d;
    cin >> l >> r >> d;
    cout << solve(l, r, d) << endl;
    return 0;
}