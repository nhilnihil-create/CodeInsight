#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a) {
    if (a % 2 == 0) return a / 2 * (a + 1);
    return (a + 1) / 2 * a;
}
int main() {
    ll a; cin >> a;
    ll ans = 0;
    for (int i = 1; i <= a; i ++) {
        ans += f(a / i) * i;
    }
    cout << ans << endl;
}