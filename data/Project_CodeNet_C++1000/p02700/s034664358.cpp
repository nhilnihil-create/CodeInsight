#include <bits/stdc++.h>

using namespace std;


int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool fg = true;
    while (a > 0 || c > 0) {
        if (fg) {
            c -= b;
            if (c <= 0) {
                cout << "Yes" << endl;
                return 0;
            }
            fg = false;
        } else {
            a -= d;
            if (a <= 0) {
                cout << "No" << endl;
                return 0;
            }
            fg = true;
        }
    }
}
