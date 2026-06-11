#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}



int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll v = b - a + 1;
    v -= b / c - (a - 1) / c;
    v -= b / d - (a - 1) / d;
    ll cd = c * d / gcd(c, d);
    v += b / cd - (a - 1) / cd;

// 6 3 2 1
// 31 (6 -1) (5-1) ()

    put(v);

    return 0;
}