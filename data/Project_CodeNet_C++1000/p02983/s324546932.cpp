#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
    ll l, r;
    cin >> l >> r;
    ll Min = 2019;
    for(ll i = min(l, r); i < max(l, r); i++) {
        for(ll j = i + 1; j <= max(l, r); j++) {
            Min = min((i * j) % 2019, Min);
            if (Min == 0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << Min << endl;

}
