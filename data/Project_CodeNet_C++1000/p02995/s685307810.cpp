#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    ll countB = b - (b / c + b / d - b / lcm(c, d));
    ll countA = a - (a / c + a / d - a / lcm(c, d));
    cout << countB - countA << endl;
}