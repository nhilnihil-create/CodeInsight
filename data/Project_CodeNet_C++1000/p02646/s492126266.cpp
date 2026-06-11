#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll a, v; cin >> a >> v;
    ll b, w; cin >> b >> w;
    ll t; cin >> t;

    ll l = abs(a - b);

    if (w >= v) {
        puts("NO");
        return 0;
    }

    ll s = v - w;
    if (l > s * t) {
        puts("NO");
    } else {
        puts("YES");
    }
}