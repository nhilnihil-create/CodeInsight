#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;

    ll l = lcm(c, d);
    ll e = (b / c) - (a - 1) / c;
    ll f = (b / d) - (a - 1) / d;
    ll g = (b / l) - (a - 1) / l;
    cout << (b - a + 1) - e - f + g << endl;


    return 0;
}
