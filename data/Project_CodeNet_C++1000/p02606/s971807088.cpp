#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 1e5+5, mod = 1e9+7;

void solve() {
    int l, r, d; cin >> l >> r >> d;

    int ans = 0, dd = d;
    while (d <= 100) {
        if (d >= l && d <= r) {
            ++ans;
        }
        d += dd;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    while (t--) solve();
    return 0;
}
