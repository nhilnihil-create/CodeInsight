#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int X;
    cin >> X;

    int happiness = X / 500;
    happiness *= 1000;
    X %= 500;
    happiness += (X / 5) * 5;
    cout << happiness << endl;

    return 0;
}
