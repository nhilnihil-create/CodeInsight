#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = 1000000000+7;
ll pow_mod(ll a, ll b) {
    if (b == 0) return 1;
    ll res = pow_mod(a, b/2);
    res = (res*res) % m;
    if (b % 2 == 0) return res;
    return (res*a) % m;
}
map<ll, ll> mm;
ll nbikkuri(ll n) {
    if (n == 0) return 1;
    if (mm.find(n) != mm.end()) return mm[n];
    return mm[n] = (nbikkuri(n-1)*n)%m;
}
ll nCr(ll n, ll r) {
    // (n!)/(r!)/((n-r)!)
    ll X = nbikkuri(n), Y = (nbikkuri(r)*nbikkuri(n-r))%m;
    return X*pow_mod(Y, m-2)%m;
}
int main () {
    ll S, ans = 0;
    cin >> S;
    for (int i = 1; i*3 <= S; i++) {
        int SS = S-i*3;
        ans += nCr(SS+i-1, SS);
        ans %= m;
    }
    cout << ans << endl;
}