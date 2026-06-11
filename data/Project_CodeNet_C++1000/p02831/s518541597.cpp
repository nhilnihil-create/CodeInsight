#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    else return gcd(y, x%y);
}

int main(int argc, char const *argv[]) {
    long long a, b;
    cin >> a >> b;

    long long ans = a * b / gcd(a, b);
    cout << ans << endl;
    return 0;
}
