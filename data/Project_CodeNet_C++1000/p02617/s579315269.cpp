#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

void solve() {
    int n; cin >> n;

    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += (ll) i * (n - i + 1);
    }

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;

        if (u > v) {
            swap(u, v);
        }

        cnt -= (ll) u * (n - v + 1);
    }
    cout << cnt << endl;
}   

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    while (t--) solve();
    return 0;
}
