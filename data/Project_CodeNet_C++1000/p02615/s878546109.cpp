#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    if (n <= 3) {
        if (n == 1) cout << 0 << endl;
        if (n == 2) cout << a[0] << endl;
        if (n == 3) cout << a[0]+a[1] << endl;
        return 0;
    }

    int ans = 0;
    priority_queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < 2; i++) ans += a[i];
    q.push({a[1], {a[0], a[1]}});
    q.push({a[2], {a[1], a[2]}});
    q.push({a[2], {a[0], a[2]}});

    for (int i = 3; i < n; i++) {
        pair<int, pair<int, int>> pp = q.top(); q.pop();
        int x = pp.second.first;
        int y = pp.second.second;
        int w = pp.first;

        ans += w;
        q.push({a[i], {x, a[i]}});
        q.push({a[i], {y, a[i]}});
    }

    cout << ans << endl;

    return 0;
}