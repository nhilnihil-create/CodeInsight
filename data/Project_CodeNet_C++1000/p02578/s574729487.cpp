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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep2(i, 1, n) {
        if (a[i] < a[i-1]) {
            ans += a[i-1]-a[i]; 
            a[i] += a[i-1]-a[i];
        }
    }
    cout << ans << endl;
    return 0;
}