#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    int64_t lcm = (int64_t) a * b / gcd(max(a, b), min(a, b));
    cout << lcm << endl;
}
