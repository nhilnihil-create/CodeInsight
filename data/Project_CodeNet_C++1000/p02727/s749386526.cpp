#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    priority_queue<ll> que;
    rep(i,x) que.push(p[i]);
    rep(i,y) que.push(q[i]);
    rep(i,c) que.push(r[i]);
    ll ans = 0;
    rep(i,x+y) {
        ans += que.top();
        que.pop();
    } 
    cout << ans << endl;
    return 0;
}