#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool win;
    while (true) {
        c -= b;
        if (c <= 0) {
            win = true;
            break;
        }
        a -= d;
        if (a <= 0) {
            win = false;
            break;
        }
    }

    if (win) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
