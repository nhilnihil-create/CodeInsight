#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
#define ld long double
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////

// greedy

int main() {
    ll n; cin >> n;
    Vp p(n);
    rep(i, 0, n){
        ll x, l; cin >> x >> l;
        p[i].fi = x+l, p[i].se = x-l;
    }
    sort(ALL(p));
    rep(i, 0, n) swap(p[i].fi, p[i].se);
    ll bl = p[0].fi, br = p[0].se;
    ll cnt = 0;
    rep(i, 1, n){
        if(p[i].fi < br) cnt++;
        else br = p[i].se;
    }
    co(n-cnt);

    return 0;
}
