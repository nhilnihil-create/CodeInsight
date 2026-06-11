#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define debug(x) cerr <<__LINE__<< ": " <<#x<< " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    int n;
    cin >> n;
    ll d, a;
    cin >> d >> a;
    d *= 2;
    vector<pll> M(n);
    rep(i, n) {
        ll x, h;
        cin >> x >> h;
        M[i] = {x, h};
    }
    ll ans = 0;
    ll acc = 0;
    sort(all(M));
    queue<pll> que;
    rep(i, n) {
        ll x, h;
        tie(x, h) = M[i];
        while (!que.empty() && que.front().fi < x) {
            acc -= que.front().se;
            que.pop();
        }
        if (acc * a >= h) continue;
        ll y = (h - (acc * a) + a - 1) / a;
        ans += y;
        acc += y;
        que.emplace(x + d, y);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
