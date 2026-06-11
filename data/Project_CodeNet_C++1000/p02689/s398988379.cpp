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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> H(n);
    rep(i, n) cin >> H[i];
    vector<int> G[101010];
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    int ans = 0;
    rep(i, n) {
        bool ii = 1;
        for (auto v : G[i]) {
            if (H[v] >= H[i]) ii = 0;
        }
        ans += ii;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
