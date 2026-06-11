#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll pred = 0;
    ll v = a[0];
    repi(i, n) {
        ll gcd = GCD(v, a[i]);
        v = v * (a[i]) / gcd;
    }
    v /= 2;
    rep(i, n) {
        if (v % a[i] != a[i] / 2) {
            put(0);
            return;
        }
    }

    put((m / v + 1) / 2);
}
signed main(){ Main();return 0;}