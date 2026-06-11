#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), c(3, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll cnt = 0;
        int id = -1;
        if (a[i] == c[0]) cnt++, id = 0;
        if (a[i] == c[1]) cnt++, id = 1;
        if (a[i] == c[2]) cnt++, id = 2;
        if (id == -1) {
            cout << 0 << endl;
            return 0;
        }
        ans *= cnt;
        ans %= mod;
        c[id]++;
    }
    cout << ans << endl;
    return 0;
}