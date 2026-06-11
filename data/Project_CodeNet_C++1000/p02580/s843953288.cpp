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
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> H[h + 1], W[w + 1];
    int hmax = 0, wmax = 0;
    map<pii, bool> mp;
    while(m--) {
        int i, j;
        cin >> i >> j;
        mp[pii(i, j)] = 1;
        H[i].pb(j);
        chmax(hmax, (int) H[i].size());
        W[j].pb(i);
        chmax(wmax, (int) W[j].size());
    }
    vector<int> HM, WM;
    rep(i, h + 1) if (H[i].size() == hmax) HM.pb(i);
    rep(i, w + 1) if (W[i].size() == wmax) WM.pb(i);
    int ans = hmax + wmax - 1;
    for(auto i : HM) for(auto j : WM) {
        if (!mp[pii(i, j)]) {
            ans++;
            cout << ans << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
