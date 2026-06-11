#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];
    sort(ALL(p), greater<int>());
    sort(ALL(q), greater<int>());
    sort(ALL(r), greater<int>());

    vector<int> ans;
    rep(i, x) ans.push_back(p[i]);
    rep(i, y) ans.push_back(q[i]);
    sort(ALL(ans));
    int rcnt = 0;
    int n = min(c, (int)ans.size());
    rep(i, n) {
        if(r[rcnt] >= ans[i]) {
            ans[i] = r[rcnt];
            rcnt++;
        } else break;
    }
    ll res = 0;
    for(auto x : ans) res += x;
    cout << res << endl;

    return 0;
}