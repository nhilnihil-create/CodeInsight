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
void Main()
{
    ll n;
    cin >> n;

    vector<vector<ll>> c(10, vector<ll>(10));

    repi(x, n + 1) {
        ll j = x % 10;
        ll i = x;
        while (i / 10 > 0) {
            i /= 10;
        }
        c[i][j]++;
    }

    ll res = 0;
    rep(i, 10) {
        rep(j, 10) {
            res += c[i][j] * c[j][i];
        }
    }

    put(res);

}
signed main(){ Main();return 0;}