#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    ll n, m, k;
    ll ans = 0;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i, n) {
        ll A;
        cin >> A;
        a.at(i) = a.at(max(i-1, 0LL)) + A;
    }
    rep(i, m) {
        ll A;
        cin >> A;
        b.at(i) = b.at(max(i-1, 0LL)) + A;
    }
    rep(i, n) {
        ll x = k - a.at(i);
        if(x < 0) break;
        auto position = upper_bound(b.begin(), b.end(), x);
        ll low_idx = distance(b.begin(), position);
        chmax(ans, i + low_idx + 1);
    }
    rep(i, m) {
        ll x = k - b.at(i);
        if(x < 0) break;
        auto position = upper_bound(a.begin(), a.end(), x);
        ll low_idx = distance(a.begin(), position);
        chmax(ans, i + low_idx + 1);
    }
    cout << ans << endl;
}