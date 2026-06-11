#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    rep (i,A) cin >> p[i];
    rep (i,B) cin >> q[i];
    rep (i,C) cin >> r[i];
    // 降順(リバースイテレーター)
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    vector<int> d;
    rep(i,X) d.push_back(p[i]);
    rep(i,Y) d.push_back(q[i]);
    rep(i,C) d.push_back(r[i]);
    sort(d.rbegin(), d.rend());
    ll ans = 0;
    rep(i,X+Y) ans += d[i];
    cout << ans << endl;

}