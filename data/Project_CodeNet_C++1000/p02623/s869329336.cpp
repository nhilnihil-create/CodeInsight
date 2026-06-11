#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n+1), b(m+1, 0);
    for (int i = 0; i < n; i++) cin >> a[i+1];
    for (int i = 0; i < m; i++) cin >> b[i+1];

    vector<ll> pa(n+1), pb(m+1);
    for (int i = 1; i <= n; i++) pa[i] = pa[i-1] + a[i];
    for (int i = 1; i <= m; i++) pb[i] = pb[i-1] + b[i];

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (pa[i] > k) break;
        if (pa[i] == k) {
            ans = max(ans, i); continue;
        }
        auto x = upper_bound(pb.begin(), pb.end(), k-pa[i]);
        if (x == pb.begin()) ans = max(ans, i);
        else {
            --x;
            ans = max(ans, i + (x-pb.begin()));
        }
    }

    cout << ans << endl;

    return 0;
}