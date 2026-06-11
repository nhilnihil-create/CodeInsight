#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll x; cin >> x;
    ll ans_a;
    ll ans_b;
    for (ll a = -1000; a <= 1000; a++) {
        for (ll b = -1000; b <= 1000; b++) {
            ll tmpa = a * a * a * a * a;
            ll tmpb = b * b * b * b * b;
            if (tmpa - tmpb == x) {
                ans_a = a;
                ans_b = b;
            }
        }
    }
    cout << ans_a << " " << ans_b << endl;
    return 0;
}