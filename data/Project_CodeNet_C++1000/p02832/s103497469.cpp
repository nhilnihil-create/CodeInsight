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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll target = 1;
    ll res = 0;
    rep(i, n) {
        if (target == a[i]) {
            target++;
        }
        else {
            res++;
        }
    }

    if (n == res) {
        put(-1);
    }
    else {
        put(res);
    }
    
}
signed main(){ Main();return 0;}