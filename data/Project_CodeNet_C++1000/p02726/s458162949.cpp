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
    ll n, X, Y;
    cin >> n >> X >> Y;

    X--;
    Y--;

//    vector<vector<ll>> d(n, vector<ll>(n));
    vector<ll> cnt(n);
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll d = min(abs(i - j), abs(X - i) + 1 + abs(Y - j));
            cnt[d]++;
        }
    }

    repi(k, n) {
        put(cnt[k]);
    }
}
signed main(){ Main();return 0;}