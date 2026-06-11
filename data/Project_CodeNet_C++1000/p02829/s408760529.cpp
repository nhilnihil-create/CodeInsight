#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    switch (A) {
        case 1:
            if (B == 2) {
                cout << 3 << endl;
            } else {
                cout << 2 << endl;
            }
            break;
        case 2:
            if (B == 1) {
                cout << 3 << endl;
            } else {
                cout << 1 << endl;
            }
            break;
        default:
            if (B == 1) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
    }
}