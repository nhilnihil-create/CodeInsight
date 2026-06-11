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
    int n, k; cin >> n >> k;
    vector<P> ans;
    FOR(i, 1, n) ans.emplace_back(i, n);
    int tot = (n-1)*(n-2)/2; // (n-1)Cr *r=2
    debug(tot);
    if (k>tot) {
        cout << -1 << endl;
        return 0;
    }
    FOR(i, 1, n) {
        FOR(j, i+1, n) {
            if (tot==k) break;
            ans.emplace_back(i, j);
            tot--;
            debug(tot);
        }
        if (tot==k) break;
    }
    debug(tot);

    cout << sz(ans) << endl;
    for(const auto& p: ans) cout << p.fi << " " << p.se << endl;
}