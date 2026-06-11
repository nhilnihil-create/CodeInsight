#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll a, b, c, d, ans = -1e18;
    cin >> a >> b >> c >> d;
    ans = max(a * c, ans);
    ans = max(a * d, ans);
    ans = max(b * c, ans);
    ans = max(b * d, ans);
    cout << ans << '\n';
    return 0;
}
