#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
// #define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
 
/*--------------------------------------------------------------------------------
 
--------------------------------------------------------------------------------*/
 
 int main() {
    ll n; cin >> n;
    Vl a(n+1);
    rep(i, 0, n+1) cin >> a[i];
 
    Vl Ma(n+1, 0), mi(n+1, 0); // 最大の葉の個数、最小の葉の個数
    Ma[n] = a[n];
    mi[n] = a[n];
    for(int i = n-1; i >= 0; i--){
        Ma[i] = Ma[i+1] + a[i];
        mi[i] = (mi[i+1]+1)/2 + a[i];
    }
    if(mi[0] > 1){
        co(-1);
        return 0;
    }
    if(n == 0 && a[0] != 1){
        co(-1);
        return 0;
    }
    // rep(i, 0, n+1) cout << mi[i] << " \n"[i==n];
    // rep(i, 0, n+1) cout << Ma[i] << " \n"[i==n];
    ll e = 1;
    ll ans = 0;
    rep(i, 0, n+1){
        chmin(e, Ma[i]); // eはMa[i]を超えない
        if(e < mi[i]){ // e >= mi[i] でなければグラフを作れない
            co(-1);
            return 0;
        }
        ans += e; // mi[i] <= e <= Ma[i];
        e -= a[i];
        e *= 2;
    }
    co(ans);

    return 0;
}