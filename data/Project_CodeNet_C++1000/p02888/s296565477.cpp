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
    vector<ll> L(n);
    rep(i, n) cin >> L[i];
    
    sort(all(L));

    ll sum = 0;
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll a = L[i];
            ll b = L[j];
            ll c_max = a + b - 1;
            ll c_min = abs(a - b) + 1;
            ll k1 = lower_bound(L.begin() + j + 1, L.end(), c_min) - L.begin();
            ll k2 = upper_bound(L.begin() + j + 1, L.end(), c_max) - L.begin();
            sum += k2 - k1;
        }
    }

    put(sum);
}
signed main(){ Main();return 0;}