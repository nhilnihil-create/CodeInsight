#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ll l, r; cin >> l >> r;
    r = min(r, l + 2019);
    ll ans = 2018;
    for (ll i = l; i <= r; ++i) {
        for (ll j = i + 1; j <= r; ++j) {
            ans = min(ans, (1LL * i * j) % 2019);
        }
    }
    cout << ans << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/