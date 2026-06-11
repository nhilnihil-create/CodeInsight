#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr <<__LINE__<< ": " << #x << " -> " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" -> ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll beki(ll x, ll n, const ll &p) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

void solve() {
    string s;
    cin >> s;
    int cnt[2020] = {0};
    cnt[0]++;
    reverse(all(s));
    int now = 0;
    rep(i, (int)s.size()) {
        now = (now + (s[i] - '0') * beki(10, i, 2019)) % 2019;
        cnt[now]++;
    }
    ll ans = 0;
    rep(i, 2019) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
