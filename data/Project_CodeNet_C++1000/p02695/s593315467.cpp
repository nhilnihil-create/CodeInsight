#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = long long ;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

vvi all;

void def(ll count, ll i, ll n, ll m, vi x){
    if(count == n) {
        all.push_back(x);
        return;
    }
    for(ll j=i; j<=m; j++){
        x.at(count) = j;
        def(count+1,j,n,m,x);
    }
}

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n,m,q;
    cin >> n >> m >> q;
    vi a(q),b(q),c(q),d(q);
    rep(i,q) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
    vi x(n);
    def(0,1,n,m,x);
    ll res = 0;
    for(vi v:all){
        ll point = 0;
        rep(i,q){
            if(v.at(b.at(i)-1)-v.at(a.at(i)-1)==c.at(i)) {
                point += d.at(i);
            }
        }
        res = max(res, point);
    }
    cout << res << endl;
}