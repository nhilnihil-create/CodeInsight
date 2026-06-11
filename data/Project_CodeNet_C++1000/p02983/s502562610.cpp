// 6/26 解き直し → 6/30
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;

int main() {
    ll L, R;
    cin >> L >> R;

    // map<ll, ll> mp;
    // for (ll i = L; (i <= R) && (i <= L + 2019*2); i++) {
    //     mp[i % 2019] += 1;
    // }

    // ll res = -1;
    // for (auto p : mp) {
    //     // printf("mp[%d] = [%d]\n", p.first, p.second);

    //     if (res == -1) {
    //         if (p.first == 0) {
    //             res = 0;
    //             break;
    //         }
    //         else if (p.second > 1) {
    //             res = (p.first * p.first) % 2019;
    //             break;
    //         }
    //         else {
    //             res = p.first;
    //         }
    //     }

    //     else {
    //         res = (res * p.first) % 2019;
    //         break;
    //     }

    //     // if (p.first == 0) {
    //     //     res = 0;
    //     //     break;
    //     // }
    //     // else if ()
    // }

    // cout << res << endl;

    R = min(R, L + 4038);
    ll ans = 2018;
    for (ll i = L; i <= R; i++) {
        for (ll j = i + 1; j <= R; j++) {
            ans = min(ans, i*j%2019);
        }
    }
    cout << ans << endl;
    return 0;
}