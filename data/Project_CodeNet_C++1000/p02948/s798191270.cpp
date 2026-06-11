#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rrep(i, n) for(ll i = n - 1; i > -1; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(V) rep(i, V.size()) cout << V[i] << " ";
const ll INF = 1LL << 61;
const ll MOD = 1000000007 /*988244353*/;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, h, x, y, z, p, q, m, n, t, r, k, w, l, ans, i, j;
string S, T;
vl A, B;
vector<PP> vp;
void solve() {
    priority_queue<PP> pq;

    vp.pb({INF, -INF});
    sort(all(vp));
    a = 0;
    rep(i, m) {
        while(vp[a].fi == i + 1) {
            pq.push({vp[a].se, vp[a].fi});
            a++;
        }

        if(!pq.empty()) {
            x = pq.top().fi;
            pq.pop();
            ans += x;
        }
    }

    cout << ans << endl;
}
int main() {
    // cout<<fixed<<setprecision(15);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i, n) {
        cin >> x >> y;
        vp.pb({x, y});
    }
    solve();
}