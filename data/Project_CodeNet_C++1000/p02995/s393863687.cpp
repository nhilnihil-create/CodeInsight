#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
 
/*  lcm (a, b) : 2整数版
    入力：整数 a, b
    出力：aとbの最小公倍数
*/
long long lcm(long long a, long long b) {
    long long d = gcd(a, b);
    return a / d * b;
}
int main() {
    ll a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    ans = b - a + 1;
    //cout << ans << ',';
    if (c <= b && b - b%c >= a) ans -= (b - b%c - a)/c + 1;
    //cout << ans << ',';
    if (d <= b && b - b%d >= a) ans -= (b - b%d - a)/d + 1;
    //cout << ans << ',';
    if (lcm(c,d) <= b && b - b%(lcm(c,d)) >= a) ans += (b - b%(lcm(c,d)) - a )/(lcm(c,d)) + 1;
    cout << ans << endl;
    return 0;
}
