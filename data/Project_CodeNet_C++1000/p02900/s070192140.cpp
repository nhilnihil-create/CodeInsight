#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll ans = 1;
    ll a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    vector<bool>v((int)sqrt(a) + 10,0);
    for (ll i = 2; i*i <= a; i++) {
        if (v[i] == 1) continue;
        for (ll j = i ; j*j <= a; j += i) {
            v[j] = 1;
        }
        if (a%i == 0 && b%i == 0) {
            ans++;
        }
        while (a%i == 0) {
            a /= i;
        }
    }
    if (a != 1 && b%a == 0) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
