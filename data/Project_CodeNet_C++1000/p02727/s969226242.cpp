#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli x, y, a, b, c;

int main(void){
    cin >> x >> y >> a >> b >> c;
    vector<lli> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];
    vector<lli> s;
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    sort(r.rbegin(), r.rend());
    rep(i, x) s.push_back(p[i]);
    rep(i, y) s.push_back(q[i]);
    rep(i, c) s.push_back(r[i]);
    sort(s.rbegin(), s.rend());
    lli ans = 0;
    ans = accumulate(s.begin(), s.begin()+x+y, 0LL);
    cout << ans << endl;

    return 0;
}
