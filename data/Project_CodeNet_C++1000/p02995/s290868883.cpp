#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
#define int long long
using namespace std;
inline int Calc(int x, int p) {
    return x / p;
}
inline int Calc(int a, int b, int c) {
    return (Calc(a, b) + Calc(a, c) - Calc(a, b * c / __gcd(b, c)));
}
int a, b, c, d, res;
main() {
    DAU
    cin >> a >> b >> c >> d;
    cout << (b - a + 1) - (Calc(b, c, d) - Calc(a - 1, c, d));
    PLEC
}
