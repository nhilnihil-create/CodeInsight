#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    string A, B;
    cin >> a >> b;

    for (int i = 0; i < b; i++) {
        A += to_string(a);
    }
    for (int i = 0; i < a; i++) {
        B += to_string(b);
    }

    if (A < B) {
        cout << A << endl;
    } else {
        cout << B << endl;
    }
}