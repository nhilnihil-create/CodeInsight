#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

void solve() {
    ll x; cin >> x;
    ll cnt = 0;
    ll a = 100;
    while (a < x) {
        a += a / 100;
        ++cnt;
    }

    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    return 0;
}
