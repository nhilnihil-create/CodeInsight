#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, n) for (ll i = n-1; i >= 0; i--)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repd2(i, s, n) for (ll i = n-1; i >= (s); i--)

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll ans;
    if (x/k >= d) {
        ans = x - d*k;
    }
    else {
        ll a;
        a = x/d;
        k -= a;
        x -= a*d;
        if (k%2 == 1) x = abs(x-d);
        ans = x;
    }
    cout << ans << endl;
    return 0;
}