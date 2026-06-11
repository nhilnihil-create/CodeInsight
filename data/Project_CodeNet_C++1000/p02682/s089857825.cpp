#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, c, k, ans;
    cin >> a >> b >> c >> k;
    if (a + b + c == 0) ans = 0;
    else if (k - a >= 0) {
        k -= a;
        ans += a;
        if (k - b >= 0) {
            k -= b;
            if (k > 0) {
                ans -= k;
            }
        }
    }
    else ans = k;
    cout << ans << endl;
}