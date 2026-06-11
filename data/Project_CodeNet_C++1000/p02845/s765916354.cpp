#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> colors(3, 0);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        int m = 0;
        for (int k = 0; k < 3; k++) {
            if (colors[k] == a) {
                if (m == 0) {
                    colors[k]++;
                }
                m++;
            }
        }
        if (m == 0) {
            cout << 0 << endl;
            return 0;
        }
        ans *= m;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
