#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a , long long b) {
    return (a * 1ll * b) / __gcd(a , b);
}


int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    long long a , b , c , d;
    cin >> a >> b >> c >> d;

    long long ans = b - a + 1;
    ans -= b / c - (a - 1) / c;
    ans -= b / d - (a - 1) / d;
    ans += b / lcm(c , d) - (a - 1) / lcm(c , d);
    cout << ans;
}
