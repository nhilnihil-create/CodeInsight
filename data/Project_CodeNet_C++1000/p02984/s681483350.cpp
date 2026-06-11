#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
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

////////////////////////////////////////////////////////

Vl ans;

int main() {
    ll n; cin >> n;
    Vl a(n);
    ans.resize(n);
    rep(i, 0, n) cin >> a[i];

    rep(i, 0, n){
        if(i%2 == 0) ans[0] += a[i];
        else ans[0] -= a[i];
    }
    rep(i, 1, n){
        ans[i] = 2*a[i-1] - ans[i-1];
    }
    rep(i, 0, n){
        if(i) cout << " ";
        cout << ans[i];
    }
    coel;

    return 0;
}
