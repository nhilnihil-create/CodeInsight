#include <bits/stdc++.h>
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
void Main()
{
    ll n;
    cin >> n;

    vector<ll> f(n + 1, 2);
    f[0] = 0;
    f[1] = 1;

    for (ll i = 2; i <= sqrt(n); i++) {
        for (ll j = i; i * j <= n; j++) {
            if (i != j) {
                f[i * j] += 2;
            }
            else {
                f[i * j] += 1;
            }
        }
    }

    ll res = 0;
    rep(i, n + 1) {
        res += i * f[i];
    }

    put(res);
}
signed main(){ Main();return 0;}