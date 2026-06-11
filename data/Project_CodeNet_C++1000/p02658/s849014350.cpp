#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (*min_element(a.begin(), a.end()) == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    rep(i, n) {
        if (a[i] <= 1000000000000000000 / ans) ans *= a[i];
        else {
            cout << -1 << endl;
        return 0;
        }
        
    }
    // cout << pow(10, 18) << endl;
    cout << ans << endl;

    return 0;
}