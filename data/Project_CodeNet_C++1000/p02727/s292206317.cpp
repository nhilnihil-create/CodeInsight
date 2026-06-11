#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    for (int i = 0; i < a; i++) cin >> p[i];
    for (int i = 0; i < b; i++) cin >> q[i]; 
    for (int i = 0; i < c; i++) cin >> r[i];
    sort(p.begin(), p.end(), greater<ll>()); 
    sort(q.begin(), q.end(), greater<ll>()); 
    sort(r.begin(), r.end(), greater<ll>());
    vector<ll> v;
    for (int i = 0; i < x; i++) v.push_back(p[i]);
    for (int i = 0; i < y; i++) v.push_back(q[i]);
    for (auto t: r) v.push_back(t);
    sort(v.begin(), v.end(), greater<ll>()); 
    ll ans = 0;
    for (int i = 0; i < x + y; i++) ans += v[i];
    cout << ans << endl;
    return 0;
}