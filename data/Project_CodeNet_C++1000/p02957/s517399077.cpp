#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;

    if (A == 0 && B == 0 || (A + B) % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << (A + B) / 2 << endl;
    }
}