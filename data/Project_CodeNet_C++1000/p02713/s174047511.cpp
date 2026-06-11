#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans += gcd(i, gcd(j, k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
