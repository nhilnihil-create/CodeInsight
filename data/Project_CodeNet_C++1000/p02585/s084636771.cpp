#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<int> c(n);
    rep(i, n) {
        cin >> p[i];
        --p[i];
    }
    rep(i, n) cin >> c[i];
    ll ans = -1e18;
    rep(si, n) {
        int x = si;
        vector<int> s;
        ll tot = 0;
        while(1) {
            x = p[x];
            s.pb(c[x]);
            tot += c[x];
            if(x == si) break;
        }
        int l = s.size();
        ll t = 0;
        rep(i, l) {
            t += s[i];
            if(i + 1 > k) break;
            ll now = t;
            if(tot > 0) {
                ll e = (k - i - 1) / l;
                now += tot * e;
            }
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
