#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if(a%b) {
        return gcd(b, a % b);
    } else {
        return b;
    }
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main()
{
    ll a, b;
    int c, d;
    cin >> a >> b >> c >> d;

    ll ans = b - a + 1;

    ll rd = b / d;
    ll ld = b / c;
    ll dd = rd + ld - b / lcm(c, d);

    ll rc = (a - 1) / d;
    ll lc = (a - 1) / c;
    ll cc = rc + lc - (a - 1) / lcm(c, d);

    ans -= dd - cc;

    cout << ans << "\n";
}

