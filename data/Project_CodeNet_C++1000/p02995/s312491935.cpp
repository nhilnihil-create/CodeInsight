#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int gcd(ll a, ll b) {
    if(a % b == 0) return b;
    else return(gcd(b, a % b));
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    ll l = c / gcd(c, d) * d;
    cout << (b - b / c - b / d + b / l) - (a - a / c - a / d + a / l) << endl;
    return 0;
}
