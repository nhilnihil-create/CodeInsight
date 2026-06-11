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

  //  ll v = a[0];

    ll v = a[0] / 2;
    repi(i, n) {
        ll gcd = GCD(v, a[i]/2);
        v = v * (a[i]/2) / gcd;
    }

    ll cnt = 0;
    ll t = a[0];
    while (t % 2 == 0) {
        t /= 2;
        cnt++;
    }
    ll refCnt = cnt;
    repi(i, n) {
        ll cnt = 0;
        ll t = a[i];
        while (t % 2 == 0) {
            t /= 2;
            cnt++;
        }
        if (cnt != refCnt) {
            put(0);
            return;
        }
    }

    if (m < v) {
        put(0);
        return;
    }

    cout << ((m / v + 1) / 2) << endl;
//    put(1 + (m - v) / (2 * v));

//     ll v = a[0] / 2;
//     repi(i, n) {
//         ll gcd = GCD(v, a[i]);
//         v = v * (a[i]) / gcd;
//     }
//     v /= 2;
//     rep(i, n) {
//         if (v % a[i] != a[i] / 2) {
//             put(0);
//             return;
//         }
//     }

//    put(1 + (m - v) / (2 * v));


}
signed main(){ Main();return 0;}