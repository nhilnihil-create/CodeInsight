#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    string s, t; cin >> s >> t;
    ll n = (ll)sz(s);
    map<char, vector<int>> mp;
    rep(i, n) {
        mp[s[i]].push_back(i+1);
    }

    ll ans = 0;
    int loc = 0;
    bool ok = true;
    rep(i, sz(t)) {
        char c = t[i];
        if (mp[c].empty()) {ok = false; break;}
        auto it = lower_bound(all(mp[c]), loc+1);
        if (it==mp[c].end()) {
            ans += (n-loc);
            ans += mp[c][0];
            loc = mp[c][0];
        } else {
            ans += (*it-loc);
            loc = *it;
        }
        debug(c, loc, ans);
    }
    if (!ok) cout << -1 << endl;
    else cout << ans << endl;
}