#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int X,Y,A,B,C; cin >> X >> Y >> A >> B >> C;
    vecl p(A);
    vecl q(B);
    vecl r(C);
    REP(i,A) cin >> p[i];
    REP(i,B) cin >> q[i];
    REP(i,C) cin >> r[i];
    sort(p.begin(),p.end(),greater<ll>());
    sort(q.begin(),q.end(),greater<ll>());
    sort(r.begin(),r.end(),greater<ll>());
    vecl res;
    REP(i,X) res.push_back(p[i]);
    REP(i,Y) res.push_back(q[i]);
    REP(i,C) res.push_back(r[i]);
    sort(res.begin(),res.end(),greater<ll>());
    ll ans = 0;
    REP(i,X+Y) ans += res[i];
    cout << ans << endl;
}
