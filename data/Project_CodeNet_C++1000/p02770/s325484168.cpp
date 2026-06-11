#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,q;
ll d[5010];
ll p[5010];
ll b[5010];
ll n,m,x;

void solve() {
    for (int i = 1; i <= k; i++) {
        p[i] = d[i-1] % m;
        if (p[i] == 0) p[i] = m;
    }
    b[0] = 0;
    for (int i = 1; i <= k; i++) {
        b[i] = b[i-1] + p[i];
    }
    ll ans = n - 1;
    ll sum = x % m;
    sum += (n - 1) / k * b[k];
    ans -= sum / m;
    sum %= m;
    sum += b[(n - 1) % k];
    ans -= sum / m;
    // cout << sum % m << endl;
    cout << ans << endl;
}

int main() {
    cin >> k >> q;
    for (int i = 0; i < k; i++) cin >> d[i];
    for (int i = 0; i < q; i++) {
        cin >> n >> x >> m;
        solve();
    }
    return 0;
}