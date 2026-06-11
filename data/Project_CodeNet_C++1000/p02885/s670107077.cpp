#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A <= B) {
        cout << 0 << endl;
    } else if (A < 2 * B) {
        cout << 0 << endl;
    } else {
        cout << A - B - B << endl;
    }
}