#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());
    priority_queue<ll, vector<ll>> que;
    rep(i,x) que.push(p[i]);
    rep(i,y) que.push(q[i]);
    ll total = 0;
    int j = 0, count = 0;
    rep(i,x+y) {
        if (j == c) break;
        if (que.top() > r[j]) {
            total += que.top();
            que.pop();
            count++;
        } else {
            total += r[j];
            j++;
        }
    }
    rep(i,x+y-j-count) {
        total += que.top();
        que.pop();
    }
    cout << total << endl;
    return 0;
}