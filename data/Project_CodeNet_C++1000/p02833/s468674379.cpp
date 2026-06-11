#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll d = 5;
    while (d <= n && n%2 == 0) {
        ans += (n/d)/2;
        d *= 5;
    }
    cout << ans << endl;
    return 0;
}
