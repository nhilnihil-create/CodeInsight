#include <bits/stdc++.h>
using namespace std;

void run() {
    int x, y;
    cin >> x >> y;
    if (y - 2 * x >= 0 && (y - 2 * x) % 2 == 0) {
        int b = (y - 2 * x) / 2;
        int a = x - b;
        if (a >= 0) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    run();
    return 0;
}
