#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll x ,ll a, ll b) {
    return (a * x) / b - a * (x / b);
}

int main() {

    ll a, b, n; cin >> a >> b >> n;
    ll ans;
    if (n < b) ans = func(n, a, b);
    else ans = func(b - 1, a, b);
    cout << ans << endl;
    return 0;
}