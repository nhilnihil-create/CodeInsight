#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define chmax(x,y) x = max(x, y)
#define chmin(x,y) x = min(x, y)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b);
    priority_queue<int> r;
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    sort(rall(p));
    sort(rall(q));
    rep(i, x) r.push(p[i]);
    rep(i, y) r.push(q[i]);
    rep(i, c) {
        int r1;
        cin >> r1;
        r.push(r1);
    }
    ll ans = 0;
    rep(i, x + y) {
        int g = r.top();
        r.pop();
        ans += (ll) g;
    }
    cout << ans << endl;
    return 0;
}
