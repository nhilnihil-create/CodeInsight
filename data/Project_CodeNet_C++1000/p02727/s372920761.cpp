#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(all(p));
    sort(all(q));
    sort(all(r));
    reverse(all(p));
    reverse(all(q));
    reverse(all(r));
    vector<ll> v;
    ll ans = 0;
    rep(i,x) v.push_back(p[i]);
    rep(i,y) v.push_back(q[i]);
    rep(i,c) v.push_back(r[i]);
    sort(all(v));
    reverse(all(v));
    rep(i,x+y) ans += v[i];
    cout << ans << endl;
    return 0;
}