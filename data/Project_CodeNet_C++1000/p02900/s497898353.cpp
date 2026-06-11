#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int MN = 1e5 + 5, LN = 17, MOD = 1e9 + 7, INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll a, b; cin >> a >> b;
    ll d = gcd(a, b);
    int cnt = 1;
    for (ll x = 2; x <= sqrt(d); x++) {
        if (d % x == 0) {
            cnt++;
            while (d % x == 0) d /= x;
        }
    }
    if (d > 1) cnt++;
    cout << cnt << '\n';
    return 0;
}
