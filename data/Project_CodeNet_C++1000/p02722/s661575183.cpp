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
#define debug(x) cerr <<__LINE__<< ": " << #x << " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll n;
ll ans = 1;

map<ll, int> prime_factor(ll n) {
    map<ll, int> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

void dfs(vector<pair<ll, int>> &div, int i, ll acc) {
    if (i == div.size()) {
        if (acc == 1) return;
        ll x = n;
        while(x % acc == 0) x /= acc;
        if (x % acc == 1) {
            ans++;
        }
        return;
    }

    auto nxt = div[i];

    rep(j, nxt.se + 1) {
        dfs(div, i + 1, acc * pow(nxt.fi, j));
    }
}

void solve() {
    cin >> n;
    auto div = prime_factor(n - 1);
    for (auto d: div) ans *= d.se + 1;
    ans--;
    div = prime_factor(n);
    vector<pair<ll, int>> X;
    for(auto d : div) X.push_back(d);
    dfs(X, 0, 1);
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
