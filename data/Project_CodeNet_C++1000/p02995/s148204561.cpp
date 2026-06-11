#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

long gcd(long a, long b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long lcm(long a, long b) {
    long c = gcd(a, b);
    return a * b / c;
}

long div(long a, long b, long p) { // a以上b以下の整数のうちpで割り切れる数の個数
    return b / p - (a - 1) / p;
}

int main() {
    long a, b, c, d;
    cin >> a >> b >> c >> d;
    long e = lcm(c, d);
    long n = b - a + 1;
    long p, q, r;
    p = div(a, b, c);
    q = div(a, b, d);
    r = div(a, b, e);
    cout << n - (p + q - r) << endl;
}