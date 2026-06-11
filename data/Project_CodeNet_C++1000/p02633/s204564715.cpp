#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

int lcm(int x, int y) { return x * y / gcd(x, y); }

int main() {
    //
    int num;
    cin >> num;

    cout << lcm(num, 360) / num;
    //
}