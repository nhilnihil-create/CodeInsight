#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    ll x,y,a,b,c; cin >> x >> y >> a >> b >> c;
    ll ans = 0;
    vector<ll> p(a),q(b),r(c);
    priority_queue<ll> apple;

    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];

    sort(p.begin(),p.end(),greater<>());
    sort(q.begin(),q.end(),greater<>());
    sort(r.begin(),r.end(),greater<>());

    rep(i,x){
        apple.push(p[i]);
    }
    rep(i,y) {
        apple.push(q[i]);
    }

    rep(i,c){
        apple.push(r[i]);
    }

    rep(i,x+y){
        ans += apple.top();
        apple.pop();
    }
    cout << ans;


}