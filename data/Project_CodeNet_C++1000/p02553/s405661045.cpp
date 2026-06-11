#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = a * c;
    chmax(ans, a * d);
    chmax(ans, b * c);
    chmax(ans, b * d);
    cout << ans << endl;
}
