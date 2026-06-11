#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;

    for (int i = 1; i <= X; i++) {
        int r = X - 100 * i;
        if (0 <= r && r <= 5 * i) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}