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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int ans = a.back();
    int pre = INF;
    vector<P> xy;
    rep(i, n-1) {
        if (a[i]<0&&a[i+1]<0) {
            xy.emplace_back(ans, a[i]);
            ans -= a[i];
        } else {
            if (pre == INF) pre = a[i];
            else {
                xy.emplace_back(pre, a[i]);
                pre -= a[i];
            }
        }
    }
    if (pre!=INF) xy.emplace_back(ans, pre);
    if (pre!=INF) ans -= pre;
    cout << ans << endl;
    for(const auto& p: xy) {
        cout << p.fi << " " << p.se << endl;
    }
}