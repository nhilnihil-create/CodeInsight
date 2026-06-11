#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll X = 0;
    rep(i, n) X ^= a[i];

    rep(i, n) {
        ll res = X ^ a[i];
        cout << res << (i == n - 1 ? "" : " "); 
    }

    cout << endl;

}
signed main(){ Main();return 0;}