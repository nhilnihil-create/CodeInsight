#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool count = true;
    while (a > 0 && c > 0) {
        if (count == true) {
            c -= b;
        } else {
            a -= d;
        }
        count = !count;
    }
    if (count == false) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
