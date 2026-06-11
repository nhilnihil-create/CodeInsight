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
#define pb push_back
#define debug(x) cerr <<__LINE__<< ": " <<#x<< " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> P(a), Q(b), R(c);
    rep(i, a) cin >> P[i];
    rep(i, b) cin >> Q[i];
    rep(i, c) cin >> R[i];
    sort(rall(P));
    sort(rall(Q));
    sort(rall(R));
    P.erase(P.begin() + x, P.end());
    Q.erase(Q.begin() + y, Q.end());
    vector<int> S;
    for(auto p : P) S.push_back(p);
    for(auto q : Q) S.push_back(q);
    for(auto r : R) S.push_back(r);
    sort(rall(S));
    ll ans = 0;
    rep(i, x + y) {
        ans += S[i];
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
