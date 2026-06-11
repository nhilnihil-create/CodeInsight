#include <bits/stdc++.h>
#define INF 1e9
#define INFLL 1ull<<60u
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int X,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;
    vector<int> red(A),green(B),no(C);
    REP(i,A) cin >> red[i];
    REP(i,B) cin >> green[i];
    REP(i,C) cin >> no[i];
    sort(ALL(red));
    sort(ALL(green));
    sort(ALL(no));
    reverse(ALL(red));
    reverse(ALL(green));
    reverse(ALL(no));
    priority_queue<int> q;
    REP(i,X) q.push(red[i]);
    REP(i,Y) q.push(green[i]);
    REP(i,C) q.push(no[i]);
    ll ans = 0;
    REP(i,X+Y) {ans += q.top(); q.pop();}
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}