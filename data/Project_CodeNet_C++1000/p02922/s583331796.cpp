#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (b == 1) {
        cout << 0 << endl;
    } else {
        int r = (b-1) / (a-1);
        if ((b-1) % (a-1) == 0) {
            cout << r << endl;
        } else {
            cout << r + 1 << endl;
        }
    }

    return 0;
}
