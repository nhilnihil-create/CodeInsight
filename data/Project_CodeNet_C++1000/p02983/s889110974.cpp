#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    ll l,r;
    cin >> l >> r;
    int ret = 0;
    if ((l/2019 == r/2019)&&(l%2019 != 0)) {
        ret = 2018;
        ll s = l % 2019;
        ll f = r % 2019;
        for (ll i = s; i <= f; i++) {
            for (ll j = i + 1; j <= f; j++) {
                if (i * j % 2019 < ret) {
                    ret = i * j % 2019; 
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}