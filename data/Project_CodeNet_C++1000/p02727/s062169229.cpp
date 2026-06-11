// Youtube解説AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;

int main() {
    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a);
    vector<ll> q(b);
    vector<ll> r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(p.begin(),p.end(),greater<ll>());
    sort(q.begin(),q.end(),greater<ll>());
    vector<ll> pq;
    rep(i,x) pq.push_back(p[i]);
    rep(i,y) pq.push_back(q[i]);
    rep(i,c) pq.push_back(r[i]);
    sort(pq.begin(),pq.end(),greater<ll>());
    ll sum = 0;
    rep(i,x+y)
        sum+=pq[i];
    cout << sum << endl;
    return 0;
}