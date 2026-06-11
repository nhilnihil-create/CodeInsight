#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
vector<vector<ll>> t;
vector<ll> v, s;
vector<bool> ok;
void dfs(ll p, ll c ){
    s[p] = c + v[p];
    ok[p] = 1;
    for (auto q : t[p]) {
        if (!ok[q]) dfs(q, c + v[p]);
    }
}
int main() {
    ll n, q;
    cin >> n >> q;
    t.resize(n, vector<ll>(0));
    v.resize(n, 0);
    s.resize(n, 0);
    ok.resize(n, 0);
    ll a, b;
    rep(i, n - 1){
        cin >> a >> b;
        t[a - 1].push_back(b - 1);
        t[b - 1].push_back(a - 1);
    }
    ll p, x;
    rep(i, q) {
        cin >> p >> x;
        v[p - 1] += x;
    }
    //cout << 'a' << endl;
    dfs(0,0);
    rep(i, n) cout << s[i] << endl;
    return 0;
}
