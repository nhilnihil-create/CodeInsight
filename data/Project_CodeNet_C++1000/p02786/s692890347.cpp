#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    cin >> n;
    ll ans = 1;
    ll p = 1;
    while (n > 1) {
        p *= 2;
        ans += p;
        n /= 2;
    }
    cout << ans << endl;
    return 0;
}
