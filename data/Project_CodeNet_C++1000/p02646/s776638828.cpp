#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll a, v;
    cin >> a >> v;
    ll b, w;
    cin >> b >> w;
    ll t;
    cin >> t;
    ll distance = abs(b - a);
    ll d_p_s = v - w;
    if (distance <= d_p_s * t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

