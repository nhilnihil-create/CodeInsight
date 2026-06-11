#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

int main() {
    int x; cin >> x;
    int m = lcm(x, 360);
    cout << m / x << endl;
    return 0;
}
