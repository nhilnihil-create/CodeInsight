#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = a * c, y = a * d, p = b * c, q = b * d;
    cout << max(x, max(y, max(p, q))) << endl;
    return 0;
}
