#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    ll n;
    cin >> n;
    vector<ll> g;

    for (ll i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            if (i != 1) g.push_back(i);
            if (n/i != i) g.push_back(n/i);
        }
    } 
    for (ll i = 1; i*i <= n-1; i++) {
        if ((n-1)%i == 0) {
            if (i != 1) g.push_back(i);
            if ((n-1)/i != i) g.push_back((n-1)/i);
        }
    } 

    int ans = 0;
    for (ll x : g) {
        ll dn = n;
        while (dn >= x) {
            if (dn%x == 0) dn /= x;
            else dn %= x;
        }
        if (dn == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}