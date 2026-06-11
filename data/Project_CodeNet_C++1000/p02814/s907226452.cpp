#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vt<int> a(n);
    for (int &i : a) cin >> i, i /= 2;

    int mx = *max_element(all(a));

    ll lcm = 1;
    for (int i : a) {
        int r = mx % i;
        int g = i / __gcd(r, i);
        lcm *= g / __gcd((ll)g, lcm);

        if (lcm * mx > m || ~(g * mx / i) & 1 || ~g & 1)
            return cout << 0, 0;
    }

    cout << (m / lcm / mx + 1) / 2;
}
