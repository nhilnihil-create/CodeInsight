#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll ans;
ll a[1<<18],b[1<<18];

int pre(int i) {
    return (i + n - 1) % n;
}

int nxt(int i) {
    return (i + 1) % n;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<pair<ll,ll>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({a[i],i});
    }
    while (!pq.empty()) {
        ll num = pq.top().first;
        ll id = pq.top().second;
        pq.pop();
        ll k = (num - b[id]) / (a[pre(id)] + a[nxt(id)]);
        ans += k;
        a[id] -= k * (a[pre(id)] + a[nxt(id)]);
        if (a[id] == b[id]) continue;
        if (k == 0 && a[id] != b[id]) {
            cout << -1 << endl;
            return 0;
        }
        pq.push({a[id], id});
    }

    cout << ans << endl;
    return 0;
}
