#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, y500, y5;
    cin >> X;
    y500 = X / 500;
    X %= 500;
    y5 = X / 5;
    cout << y500 * 1000 + y5 * 5 << endl;
}