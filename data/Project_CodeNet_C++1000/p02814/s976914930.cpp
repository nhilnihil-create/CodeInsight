#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    ll n,m; cin >> n >> m;
    ll lcm = 1;
    vector<ll> a(n);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i] /= 2;
        lcm = lcm / GCD(lcm,a[i]) * a[i];
    }
    ll res = m / lcm;
    ll ans;
    for (int i = 0; i < n; i++) {
        if (lcm / a[i] % 2 == 0) {
            ok = false;
            break;
        }
    }
    if (ok) ans = (res + 1) / 2;
    else ans = 0;
    cout << ans << "\n";
}