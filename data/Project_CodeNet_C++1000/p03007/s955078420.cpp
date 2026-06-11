#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
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
 
/*--------------------------------------------------------------------------------
例
1  2  10  12

-5  -2  -1  10  12  
-> -5  13  12
-> -18  12
-> 30

-4  -3  -1  10  12

0  0  0  0

-12  -10  -3  -1
--------------------------------------------------------------------------------*/


int main(){
    ll n; cin >> n;
    Vl a(n);
    bool f1 = false, f2 = false;
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] > 0) f1 = true;
        else if(a[i] < 0) f2 = true;
    }
    sort(ALL(a));
    if(f1 && !f2){
        ll ans = 0;
        ans -= a[0];
        rep(i, 1, n) ans += a[i];
        co(ans);
        ll lf = a[0];
        rep(i, 0, n-2){
            co(lf << " " << a[i+1]);
            lf -= a[i+1];
        }
        co(a[n-1] << " " << lf);
    }
    if(!f1 && f2){
        reverse(ALL(a));
        ll ans = a[0];
        rep(i, 1, n) ans -= a[i];
        co(ans);
        ll lf = a[0];
        rep(i, 0, n-1){
            co(lf << " " << a[i+1]);
            lf -= a[i+1];
        }
    }
    if(f1 && f2){
        ll ans = 0;
        rep(i, 0, n) ans += abs(a[i]);
        co(ans);
        Vl a1, a2;
        rep(i, 0, n){
            if(a[i] <= 0) a1.push_back(a[i]);
            else a2.push_back(a[i]);
        }
        rep(i, 0, sz(a2)-1){
            co(a1[0] << " " << a2[i]);
            a1[0] -= a2[i];
        }
        rep(i, 0, sz(a1)){
            co(a2[sz(a2)-1] << " " << a1[i]);
            a2[sz(a2)-1] -= a1[i];
        }
    }
    if(!f1 && !f2){
        co(0);
        rep(i, 0, n-1) co(0 << " " << 0);
    }


    return 0;
}
