#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<int> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    rep(i, x) r.push_back(p[i]);
    rep(i, y) r.push_back(q[i]);
    sort(r.begin(), r.end(), greater<int>());

    ll ans = 0;
    rep(i, x + y) ans += r[i];

    cout << ans << endl;
    return 0;
}
